package org.example.labjavafx.Repository;

import org.example.labjavafx.Domain.Entity;
import org.example.labjavafx.Validators.Validator;

import java.io.*;
import java.util.Optional;

public abstract class AbstractFileRepository<ID, E extends Entity<ID>> extends InMemoryRepository<ID, E> {
    private String filename;

    public AbstractFileRepository(Validator<E> validator, String filename) {
        super(validator);
        this.filename = filename;
        loadData();
    }

    public abstract E lineToEntity(String line);
    public abstract String entityToLine(E entity);

    @Override
    public Optional<E> save(E entity) {
        Optional<E> e = super.save(entity);
        if(e.isEmpty()) {
            writeToFile(entity);
        }
        return e;
    }

    private void writeToFile(E entity) {
        try(BufferedWriter writer = new BufferedWriter(new FileWriter(this.filename, true))) {
            writer.write(entityToLine(entity));
            writer.newLine();
        } catch(IOException e) {
            throw new RuntimeException(e);
        }
    }

    private void writeToFile() {
        try(BufferedWriter writer = new BufferedWriter(new FileWriter(this.filename, true))) {
            entities.values().stream()
                    .map(this::entityToLine)
                    .forEach(lineEntity -> {
                        try {
                            writer.write(lineEntity);
                            writer.newLine();
                        } catch (IOException e) {
                            throw new RuntimeException(e);
                        }
                    });
        }catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void loadData() {
        try(BufferedReader reader = new BufferedReader(new FileReader(this.filename))){
            String line;
            while((line = reader.readLine()) != null) {
                E entity = lineToEntity(line);
                super.save(entity);
            }
        } catch(IOException e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public Optional<E> delete(ID id) {
        Optional<E> entity = super.delete(id);
        if(entity.isPresent()) {
            writeToFile();
        }
        return entity;
    }

    @Override
    public Optional<E> update(E entity) {
        Optional<E> e = super.update(entity);
        if(e.isEmpty()) {
            writeToFile();
        }
        return e;
    }

}

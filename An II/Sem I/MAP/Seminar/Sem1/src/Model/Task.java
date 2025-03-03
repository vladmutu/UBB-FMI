package Model;

import java.util.Objects;

public abstract class Task {
    private String taskID;
    private String descriere;
    public Task(String taskID, String descriere) {
        this.taskID = taskID;
        this.descriere = descriere;
    }
    
    public String getID() {
        return this.taskID;
    }
    
    public String getDescriere() {
        return this.descriere;
    }

    public void setID(String ID) {
        this.taskID = ID;
    }

    public void setDescriere(String descriere) {
        this.descriere = descriere;
    }

    @Override
    public String toString() {
        return "Model.Task{" +
                "taskID='" + taskID + '\'' +
                ", descriere='" + descriere + '\'' +
                '}';
    }

    //equals si hashcode pentru inserare si cautare in structuri ce folosesc hashes
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Task task = (Task) o;
        return Objects.equals(taskID, task.taskID) && Objects.equals(descriere, task.descriere);
    }

    @Override
    public int hashCode() {
        return Objects.hash(taskID, descriere);
    }

    public abstract void execute();
}

package Repository;

import Domain.Prieten;
import Domain.Validators.Validator;

public class PrietenieRepository extends AbstractFileRepository<Long, Prieten> {
    public PrietenieRepository(Validator<Prieten> validator, String fileName) {
        super(validator, fileName);
    }

    @Override
    public Prieten lineToEntity(String line) {
        String[] tokens = line.split(";");
        Long id = Long.parseLong(tokens[0]);
        Long firstUserId = Long.parseLong(tokens[1]);
        Long secondUserId = Long.parseLong(tokens[2]);
        Prieten prietenie = new Prieten(firstUserId, secondUserId);
        prietenie.setId(id);
        return prietenie;
    }

    @Override
    public String entityToLine(Prieten entity) {
        return entity.getId() + ";" + entity.getUser1ID() + ";" + entity.getUser2ID();
    }
}

package Model;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class MessageTask extends Task{
    private String message;
    private String from;
    private String to;
    private LocalDateTime date;

    private static DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyy-MM-dd HH:mm");

    public MessageTask(String description, String id, String message, String from, String to, LocalDateTime date) {
        super(description, id);
        this.message = message;
        this.from = from;
        this.to = to;
        this.date = date;
    }



    @Override
    public String toString() {
        return "id="
                + getID()
                + " | description="
                + getDescriere()
                + " | message="
                + message
                + " | from="
                + from
                + " | to="
                + to
                + " | date="
                + date.format(formatter);
    }

    @Override
    public void execute() {
        System.out.println(date.format(formatter) + ":" + message);
    }


}

module org.example.demo1 {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;
    requires java.naming;
    requires javafx.base;

    opens org.example.demo1.Domain to javafx.base;
    opens org.example.demo1 to javafx.fxml;
    exports org.example.demo1;
    exports org.example.demo1.GUI;
    opens org.example.demo1.GUI to javafx.fxml;
}
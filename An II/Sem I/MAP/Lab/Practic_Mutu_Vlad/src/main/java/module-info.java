module org.example.practic_mutu_vlad {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;
    requires javafx.base;
    opens org.example.practic_mutu_vlad.Domain to javafx.base;

    opens org.example.practic_mutu_vlad to javafx.fxml;
    exports org.example.practic_mutu_vlad;
    exports org.example.practic_mutu_vlad.Controllers;
    opens org.example.practic_mutu_vlad.Controllers to javafx.fxml;
}
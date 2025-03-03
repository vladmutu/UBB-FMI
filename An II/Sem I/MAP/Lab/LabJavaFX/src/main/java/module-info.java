module org.example.labjavafx {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;
    requires org.kordamp.bootstrapfx.core;
    requires java.sql;

    opens org.example.labjavafx to javafx.fxml;
    exports org.example.labjavafx;
    exports org.example.labjavafx.Controllers;
    exports org.example.labjavafx.Domain;
    opens org.example.labjavafx.Controllers to javafx.fxml;
}
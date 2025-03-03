module org.example.demodoi {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;
    requires javafx.base;
    requires java.desktop;

    opens org.example.demodoi.Domain to javafx.base;
    exports org.example.demodoi.Domain;
    opens org.example.demodoi to javafx.fxml;
    exports org.example.demodoi;
    exports org.example.demodoi.Controllers;
    opens org.example.demodoi.Controllers to javafx.fxml;
}
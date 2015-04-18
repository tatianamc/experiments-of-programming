package sample;


import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class Controller {
    public void TestClick(ActionEvent event) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("tt.fxml"));

        Stage stage = new Stage();
        stage.setTitle("My New Stage Title");
        stage.setScene(new Scene(root, 450, 450));
        stage.show();

        //hide this current window (if this is whant you want
        //((Node)(event.getSource())).getScene().getWindow().hide();
    }
}

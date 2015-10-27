package sample;

import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.scene.control.DatePicker;
import javafx.scene.control.Label;
import javafx.scene.control.ToggleButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.text.Text;
import javafx.stage.FileChooser;

import javax.swing.*;
import java.io.File;

public class Controller {

    public ToggleButton toggleButton;
    public DatePicker dateField;

    @FXML
    private Label field;

    @FXML
    protected void handleSubmitButtonAction(MouseEvent event) {


        JOptionPane.showMessageDialog(null, dateField.getValue() );
        /*field.setText("sdfsdf");

        FileChooser fileChooser = new FileChooser();

        //Set extension filter
        FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("TXT files (*.txt)", "*.txt");
        fileChooser.getExtensionFilters().add(extFilter);

        //Show save file dialog
        File file = fileChooser.showSaveDialog(null);

        if(file != null){
           // SaveFile(Santa_Claus_Is_Coming_To_Town, file);
        }*/
    }

    
    public void check(ActionEvent actionEvent) {
        System.out.println("dsf");
        field.setText(String.valueOf(toggleButton.isSelected()));
    }

    public void sdfsdf(ActionEvent actionEvent) {
    }

    public void ttt(ActionEvent actionEvent) {
    }
}

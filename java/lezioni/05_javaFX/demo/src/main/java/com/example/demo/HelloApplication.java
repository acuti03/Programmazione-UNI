package com.example.demo;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.*;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {
	@Override
	public void start(Stage stage) throws IOException {

		Button btn1 = new Button();
		Button btn2 = new Button();

		btn1.setText("ciao");
		btn1.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				System.out.println("Hello World!");
			}
		});

		btn2.setText("sono");

		Group root = new Group();
		HBox pane = new HBox();

		pane.setLayoutX(100);
		pane.setLayoutY(100);

		root.getChildren().add(pane);
		pane.getChildren().addAll(btn1, btn2);

		Scene scene = new Scene(root, 300, 250);

		stage.setTitle("Hello World");
		stage.setScene(scene);
		stage.show();
	}

	public static void main(String[] args) {
		launch();
	}
}
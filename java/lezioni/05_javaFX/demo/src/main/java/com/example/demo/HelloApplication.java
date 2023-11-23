package com.example.demo;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.Shape;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {
	@Override
	public void start(Stage stage) throws IOException {

		Button btn1 = new Button();
		Button btn2 = new Button();
		Text text = new Text();
		Rectangle rectangle = new Rectangle(20, 20, 100, 100);
		//ImageView imageView = new ImageView();
		//imageView.setImage(image);

		btn1.setText("ciao");
		btn1.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				System.out.println("Hello World!");
			}
		});

		btn2.setText("sono");
		text.setText("prova");

		Group root = new Group();
		HBox pane = new HBox();

		pane.setLayoutX(100);
		pane.setLayoutY(200);

		root.getChildren().add(pane);
		pane.getChildren().addAll(btn1, btn2);
		root.getChildren().add(text);
		root.getChildren().add(rectangle);
		//root.getChildren().add(imageView);

		Scene scene = new Scene(root, 300, 250);

		stage.setTitle("Hello World");
		stage.setScene(scene);
		stage.show();
	}

	public static void main(String[] args) {
		launch();
	}
}
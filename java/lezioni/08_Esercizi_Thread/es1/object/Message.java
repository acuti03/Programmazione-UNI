package object;

import java.io.*;

public class Message implements Serializable{
	
	private float temp;

	public Message(float temp){
		this.temp = temp;
	}

	public float getMessage(){
		return temp;
	}
}
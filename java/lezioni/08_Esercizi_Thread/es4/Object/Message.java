package es2.Object;

import java.io.Serializable;

public class Message implements Serializable {
    
    private String message;

    public Message(String message){
        this.message = message;
    }

    public String getMessage(){
        return message;
    }
}

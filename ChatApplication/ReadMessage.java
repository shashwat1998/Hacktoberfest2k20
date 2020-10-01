//package SocketProgramming;

import java.io.DataInputStream;
import java.io.DataOutputStream;

public class ReadMessage implements Runnable{

	private DataInputStream in;
	private DataOutputStream out;
	private String message;

	public ReadMessage(DataInputStream in,DataOutputStream out){

		try{

			this.in = in;
			this.out = out;
		}
		catch(Exception e){

		}
	}

	public void run(){

		try{

			message = in.readUTF();
			System.out.println(message);
		}
		catch(Exception e){

		}
	}
}
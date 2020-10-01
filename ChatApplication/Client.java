//package SocketProgramming;

import java.io.*;
import java.util.Scanner;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;

public class Client{

	public Scanner sc;
	public Socket s = null;
	public DataInputStream in;
	public DataOutputStream out;
	private final int id ;

	public Client() throws IOException{

		while(true){
			try{
				s = new Socket("127.0.0.1",6075);
				if(s != null)
					break;
			}
			catch(Exception e){
				e.printStackTrace();
			}
		}

		System.out.println("You are now connected to the Server...");

		try{
			this.out = new DataOutputStream(s.getOutputStream());
			this.in = new DataInputStream(s.getInputStream());
		}

		catch(Exception e){
			e.printStackTrace();
		}

		id = Integer.parseInt(in.readUTF()) ;
		Thread t = new Thread(new ReadMessage(in,out)) ;
		t.start() ;
		String message;
		int recepientID ;
		sc = new Scanner(System.in);
		while(true){
			System.out.println("Enter the ID of recepient: ") ;
			recepientID = sc.nextInt() ;
			message = sc.nextLine();
			if(recepientID==-1)
				break;
			System.out.println("Enter message: ") ;
			message = sc.nextLine();
			try{
				out.writeUTF(message+"#"+Integer.toString(recepientID));
				out.flush();
			}
			catch(Exception e){

			}
		}
		
		/*
		Message m = new Message("Shivendu");

		try{
			out.writeObject(m);
		}

		catch(Exception e){
			
		}
		*/
	}

	public static void main(String args[]) throws IOException{
		new Client();
	}
}
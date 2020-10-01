//package SocketProgramming;

import java.util.*;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server{

	private static int port = 6075;
	private ServerSocket s;
	static Vector<ClientHandler> v = new Vector<>();
	static int i=0 ;	//counter for client

	//public boolean hasSecondConnected = false;
	public Socket clientSocket1 = null;//clientSocket2 = null;


	public Server(){

		try{
			s = new ServerSocket(port);
			System.out.println("Server started");
		}
		
		catch(Exception e){
			System.out.println("Could not start Server at the specified port");
		}

		while(true){

			try{
				Socket clientSocket1 = s.accept();
				System.out.println("Client Connected");
				ClientHandler c = new ClientHandler(clientSocket1,i) ;
				v.add(c) ;
				System.out.println("Client "+i+" was added to active client list") ;
				++i ;

				
				/*
				while(this.hasSecondConnected == false){

					try{
						Socket clientSocket2 = s.accept();
						System.out.println("2nd Client Connected" + "..." + "Starting Game");
						this.hasSecondConnected = true;
					}

					catch(Exception e){

					}
				}

				this.hasSecondConnected = false;
				*/
				Thread t = new Thread(c);
				t.start();
			}

			catch(Exception e){
				e.printStackTrace();
			}
		}
	}

	public static void main(String args[]){

		new Server();
	}
}
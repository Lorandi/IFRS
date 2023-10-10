import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Server implements Runnable {

    private ArrayList<ConnectionHandler> connections;
    private ServerSocket server;
    private boolean done;
    private ExecutorService pool;

    public Server() {
        connections = new ArrayList<>();
        done = false;
    }

    @Override
    public void run() {
        try {
            server = new ServerSocket(9999);
            pool = Executors.newCachedThreadPool();
            while (!done) {
                Socket client = server.accept();
                ConnectionHandler handler = new ConnectionHandler(client);
                connections.add(handler);
                pool.execute(handler);
            }
        } catch (IOException e) {
            System.out.println("Problema no run(1)");
            shutdown();
        }

    }

    public void broadcast(String message, InetAddress sender) {
        for (ConnectionHandler ch : connections) {
            if (ch != null && ch.client.getInetAddress() != sender) {
                ch.sendMessage(message);
            }
        }
    }

    public void broadcastToRoom(String message, InetAddress sender, String room) {
        for (ConnectionHandler ch : connections) {
            if (ch != null && ch.client.getInetAddress() != sender && ch.room.equals(room)) {
                ch.sendMessage(message);
            }
        }
    }

    public void shutdown() {
        try {
            done = true;
            pool.shutdown();
            if (!server.isClosed()) {
                server.close();
            }
            for (ConnectionHandler ch : connections) {
                ch.shutdown();
            }
        } catch (IOException e) {
            System.out.println("Erro no shutdown");
        }
    }

    class ConnectionHandler implements Runnable {
        private Socket client;
        private BufferedReader in;
        private PrintWriter out;
        private String nickname;
        private String room;

        public ConnectionHandler(Socket client) {
            this.client = client;
            this.room = "0";
        }

        @Override
        public void run() {

            try {
                out = new PrintWriter(client.getOutputStream(), true);
                in = new BufferedReader(new InputStreamReader(client.getInputStream()));
                var sender = client.getInetAddress();
                System.out.printf("Conexão estabelecida com %s:%d %n", sender, client.getPort());

                do{
                    out.println("Insira seu nome: ");
                    nickname = in.readLine();
                    if (nickname == null || nickname.isEmpty() || nickname.length() > 16) {
                        out.println("Nome inválido");
                    } else {
                        break;
                    }
                } while (true);

                do {
                    out.println("Escolha uma sala (1 a 5): ");
                    room = in.readLine();
                    if (room == null ||!Arrays.asList("1", "2", "3", "4", "5").contains(room)) {
                        out.println("Sala inválida");
                    } else {
                        out.println("Você entrou na sala " + room);
                        break;
                    }
                } while (true);

                System.out.println(nickname + " conectou na sala " + room + "!");

                broadcast(nickname + " entrou na sala " + room + "!", client.getInetAddress());
                String message;
                while ((message = in.readLine()) != null) {
                    if (message.startsWith("/nick ")) {
                        String[] messageSplit = message.split(" ", 2);

                        if (messageSplit.length == 2) {
                            broadcast(nickname + "trocou de nome para " + messageSplit[1], sender);
                            System.out.println(nickname + "trocou de nome para " + messageSplit[1]);
                            nickname = messageSplit[1];
                            out.println("Nome trocado para " + nickname + "com sucesso!");
                        } else {
                            out.println("Nome inválido");
                        }
                    } else if (message.startsWith("/quit")) {
                        broadcast(nickname + "Saiu do chat.", sender);
                        shutdown();
                    } else {
                        broadcastToRoom(nickname + ": " + message, sender, room);
                    }
                }
            } catch (IOException e) {
                shutdown();
            }
        }

        public void sendMessage(String message) {
            out.println(message);
        }

        public void shutdown() {
            try {
                in.close();
                out.close();
                if (!client.isClosed()) {
                    client.close();
                }
            } catch (IOException e) {
                System.out.println("Problema no shutdown de cliente");
            }
        }
    }

    public static void main(String[] args) {
        Server server = new Server();
        System.out.println("\n Server iniciado \n");
        server.run();
    }
}

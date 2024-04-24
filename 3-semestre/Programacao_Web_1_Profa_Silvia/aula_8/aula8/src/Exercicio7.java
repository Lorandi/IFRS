public class Exercicio7 {

        public static void main(String args[]) {
            System.out.println("Início do main");
            metodo1();
            System.out.println("Fim do main");
        }
        static void metodo1() {
            System.out.println("Início do metodo1");
            metodo2();
            System.out.println("Fim do metodo1");
        }
        static void metodo2() {
            System.out.println("Início do metodo2");
            int[] array = new int[5];
            for (int i = 0; i <= 5; i++) {//ArrayIndexOutOfBoundsException
                array[i] = i;
                System.out.println(i);
            }
            System.out.println("Fim do metodo2");
        }
    }


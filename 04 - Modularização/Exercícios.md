# 1. Fazer um programa e dentro dele um método que receba uma palavra (do tipo string) e uma letra (do tipo char). O método deve contar quantas vezes a letra aparece na palavra e exibir essa quantidade
```cpp
import java.util.Scanner;

public class Principal {

    public static int contarLetra(String palavra, char letra) {
        int contador = 0;
        for (int i = 0; i < palavra.length(); i++) {
            if (Character.toLowerCase(palavra.charAt(i)) == Character.toLowerCase(letra)) {
                contador++;
            }
        }
        return contador;
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        System.out.print("Digite uma palavra: ");
        String palavra = teclado.nextLine();

        System.out.print("Digite uma letra: ");
        char letra = teclado.next().charAt(0);

        int qtd = contarLetra(palavra, letra);
        System.out.println("A letra '" + letra + "' aparece " + qtd + " vez(es).");

        teclado.close();
    }
}
```

# 2. Fazer um programa e dentro dele um método que receba o dia (string), o mês (string) e o ano (string). O método deve escrever 'DATA VÁLIDA' ou 'DATA INVÁLIDA' para a situação das variáveis passadas
```cpp
import java.util.Scanner;

public class Principal {

    public static boolean validarData(String dia, String mes, String ano) {
        try {
            int d = Integer.parseInt(dia);
            int m = Integer.parseInt(mes);
            int a = Integer.parseInt(ano);

            if (a < 1 || m < 1 || m > 12 || d < 1) return false;

            int[] diasMes = {31, (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)) ? 29 : 28,
                             31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            return d <= diasMes[m - 1];
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        System.out.print("Digite o dia: ");
        String dia = teclado.nextLine();

        System.out.print("Digite o mês: ");
        String mes = teclado.nextLine();

        System.out.print("Digite o ano: ");
        String ano = teclado.nextLine();

        if (validarData(dia, mes, ano)) {
            System.out.println("DATA VÁLIDA");
        } else {
            System.out.println("DATA INVÁLIDA");
        }

        teclado.close();
    }
}
```

# 3. Fazer um programa que tenha um método que receba uma frase e retorne a quantidade de vogais presentes na frase
```cpp
import java.util.Scanner;

public class Principal {

    public static int contarVogais(String frase) {
        int contador = 0;
        frase = frase.toLowerCase();

        for (int i = 0; i < frase.length(); i++) {
            char c = frase.charAt(i);
            if ("aeiou".indexOf(c) != -1) {
                contador++;
            }
        }
        return contador;
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        System.out.print("Digite uma frase: ");
        String frase = teclado.nextLine();

        System.out.println("Quantidade de vogais: " + contarVogais(frase));

        teclado.close();
    }
}
```

# 4. Fazer um programa que tenha um método que receba uma frase e retorne essa frase totalmente em maiúscula
```cpp
import java.util.Scanner;

public class Principal {

    public static String paraMaiuscula(String frase) {
        return frase.toUpperCase();
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        System.out.print("Digite uma frase: ");
        String frase = teclado.nextLine();

        System.out.println("Frase em maiúscula: " + paraMaiuscula(frase));

        teclado.close();
    }
}
```

# 5. Fazer um programa que tenha um método que receba um vetor de números inteiros, o tamanho desse vetor e retorne true se o vetor estiver ordenado ou false se o vetor estiver desordenado
```cpp
import java.util.Scanner;

public class Principal {

    public static boolean estaOrdenado(int[] vetor, int tamanho) {
        for (int i = 0; i < tamanho - 1; i++) {
            if (vetor[i] > vetor[i + 1]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        System.out.print("Digite o tamanho do vetor: ");
        int n = teclado.nextInt();
        int[] vetor = new int[n];

        System.out.println("Digite os elementos do vetor:");
        for (int i = 0; i < n; i++) {
            vetor[i] = teclado.nextInt();
        }

        if (estaOrdenado(vetor, n)) {
            System.out.println("O vetor está ordenado.");
        } else {
            System.out.println("O vetor está desordenado.");
        }

        teclado.close();
    }
}
```

# 6. Fazer um programa que tenha um método que receba um nome completo e retorne o primeiro nome desse nome completo
```cpp
import java.util.Scanner;

public class Principal {

    public static String primeiroNome(String nomeCompleto) {
        String[] partes = nomeCompleto.trim().split(" ");
        return partes[0];
    }

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        System.out.print("Digite o nome completo: ");
        String nome = teclado.nextLine();

        System.out.println("Primeiro nome: " + primeiroNome(nome));

        teclado.close();
    }
}
```

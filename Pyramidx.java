import java.util.Scanner;

public class Pyramidx {
    public static void main(String[] args) throws Exception {
        int val=0;
        boolean flag=true, flag2=true;
        Scanner scan1 = new Scanner(System.in);
        try {
            System.out.println("Digite um valor inteiro de 6 a 16 para a formacao de linhas na piramide:");
            val = scan1.nextInt();
            
            if(val<=5 || val>16) {
                throw new RuntimeException("somente valores entre 6 e 16 sao aceitos");
            }
        }
        catch (Exception e) {
            flag2=false;
            System.out.println("Digite um valor valido... erro: " + e);
        }
        make pyramid = new make(val);
        String word = new String();
        Scanner scan2 = new Scanner(System.in);

while(flag && flag2) {
    try {
        System.out.println("De qual forma quer ver a piramide? Comandos: Lei cos sen / Up / Down / Left / Right ou digite Exit para sair");
        word = scan2.nextLine();
        if(word.equals("Up") || word.equals("Down") || word.equals("Left") || word.equals("Right") || word.equals("Lei cos sen") || word.equals("Exit") || word.equals("exit")) {
            if(word.equals("Up")) {
            pyramid.Up();
            }
            else if(word.equals("Down")) {
            pyramid.Down();    
            }
            else if(word.equals("Left")) {
            pyramid.Left();    
            }
            else if(word.equals("Lei cos sen")) {
            pyramid.Leicossen();    
            }
            else if(word.equals("Right")) {
            pyramid.Right();    
            }
            else {
                System.out.println("Fechando o programa...");
                flag = false;
            }
        }
        else {
            throw new RuntimeException("Por favor, digite um comando valido.");
        }
    }
    catch (Exception error) {
        System.out.println("error: " + error);
    }
}
scan2.close();
scan1.close();
    }
}

class make {
    public int[][] var = new int[100][100];
    public int i=0, j=0, aux1=0, def=15, v2=0, f=0;
    make(int v) {
        v2 = v;
        for(i=0;i<v;i++) {
            for(j=1;j<(i-1);j++) {
            var[i][j] = var[i][j-1]+1;
            
            }
           
            var[i+1][0] = var[i][j-1];
        }    
    }
    public void Up() {
        aux1=0;
        def=(v2-1);
        for(i=0;i<v2;i++) {
            for(j=1;j<(i-1);j++) {
                while(aux1<def) {
                aux1++;
                System.out.print("      ");     
                }
                
                if(var[i][j] < 10) {
                    System.out.print("      ");
                } 
                else if (var[i][j] < 100) {
                    System.out.print("     ");
                } 
                try { Thread.sleep (30); } catch (InterruptedException ex) {System.out.print("not possible");}
                System.out.print(var[i][j] + "     ");
            }
            def--;
            aux1=0;
            
            System.out.println("");
        }
    }
    public void Down() {
    if((v2-1)==0) {v2++;}
    aux1=(v2-1);
    def=(v2-1);    
    int cont=0;
        for(i=(v2-1);i>0;i--) {
            for(j=1;j<(i-1);j++) {
                while(aux1<def) {
                aux1++;
                System.out.print("      ");     
                }
            
                if(var[i][j] < 10) {
                    System.out.print("      ");
                } 
                else if (var[i][j] < 100) {
                    System.out.print("     ");
                } 
                try { Thread.sleep (30); } catch (InterruptedException ex) {System.out.print("not possible");}
                System.out.print(var[i][j] + "     ");
            }
            cont++;
            aux1=def-cont;
            System.out.println("");
        }
    }
    public void Leicossen() {
        aux1=0;
        def=(v2-1);
        for(i=0;i<v2;i++) {
            for(j=1;j<(i-1);j++) {
                while(aux1<def) {
                aux1++;
                System.out.print("      ");     
                }
                
                if(var[i][j] < 10) {
                    System.out.print("      ");
                } 
                else if (var[i][j] < 100) {
                    System.out.print("     ");
                } 
                try { Thread.sleep (30); } catch (InterruptedException ex) {System.out.print("not possible");}
                
                    System.out.print(var[i][j]);
                    System.out.print(" ");
            }
            def--;
            aux1=0;
            
            System.out.println("");
        }
}
public void Right() {
    aux1=0;
    def=0;
    for(i=0;i<v2;i++) {
        for(j=1;j<(i-1);j++) {
            
            if(var[i][j] < 10) {
                System.out.print(" ");
            } 
            try { Thread.sleep (30); } catch (InterruptedException ex) {System.out.print("not possible");}
            
                System.out.print(var[i][j]);
                System.out.print(" ");
        }
        System.out.println("");
    }
}
public void Left() {
    aux1=0;
    def=(v2-1);
    int cont=0;
    for(i=0;i<v2;i++) {
        for(j=1;j<(i-1);j++) {
            while(aux1<def) {
            aux1++;
            System.out.print("   ");     
            }
            if (var[i][j]>=1 && var[i][j]<4) {
                System.out.print(" ");
            }
            else if (var[i][j]>3 && var[i][j]<7) {
                System.out.print(" ");
            }
            else if (var[i][j]>6 && var[i][j]<10) {
                System.out.print(" ");
            }
            try { Thread.sleep (30); } catch (InterruptedException ex) {System.out.print("not possible");}
            System.out.print(var[i][j]);
            System.out.print(" ");
        }
        cont++;
        aux1=cont;
        
        System.out.println("");
    }
}
}

using System;

namespace Programa
{
    class matrix {
        private int[,] c = new int[100,100];
        public int i=0,j=0;
        private int n1, m1, n2, m2;
        public void Set() {
            Console.WriteLine("Digite: valor x de dentro da matrix\n valor indice n \n valor indice m");
            int x = Convert.ToInt32(Console.ReadLine());
            int n = Convert.ToInt32(Console.ReadLine());
            int m = Convert.ToInt32(Console.ReadLine());
            n2=n;
            m2=m;
            n1=n;
            m1=m;
            for(i=0;i<n;i++) {
                for(j=0;j<m;j++) {
                    c[i,j] = x;
                }
            }
        }
        public void Show() {
            
            for(i=0;i<n2;i++) {
                for(j=0;j<m2;j++) {
                    Console.Write(c[i,j]);
                    if(j!=(m2-1))
                        Console.Write(" ");

                }
                Console.WriteLine();
            }
        }
        public void Alterar() {
            Console.WriteLine("Por favor, solicita a linha n coluna m que deseja mudar: ");
            n1 = Convert.ToInt32(Console.ReadLine());
            m1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine($"Qual valor deseja na linha {n1} coluna {m1} ? ");
            c[n1,m1] = Convert.ToInt32(Console.ReadLine());
        }
        }
    class Program
    {
        static void Main(string[] args)
        {
            matrix m = new matrix();
            String palavra = "";
            bool boleano = true;

            Console.WriteLine("\nDigite o comando que deseja executar: \nexit para sair \nm.Set() para definir a matriz \nm.Show() para mostrar a matriz \nm.Alterar() para alterar a matriz: \n");

            while(boleano) {
                palavra = Console.ReadLine();
                if(palavra=="exit") {
                    boleano = false;
                }
                else if(palavra=="m.Alterar()") {
                    m.Alterar();
                }
                else if(palavra=="m.Set()") {
                    m.Set();
                }
                else if(palavra=="m.Show()") {
                    m.Show();
                }
                else {
                    Console.WriteLine("O termo digitado não existe.");
                }
            Console.WriteLine("\nDigite o comando que deseja executar: \nexit para sair \nm.Set() para definir a matriz \nm.Show() para mostrar a matriz \nm.Alterar() para alterar a matriz: \n");    
            }
        }
    }
}

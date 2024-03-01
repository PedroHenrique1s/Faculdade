//Exercícios C# 
/*
1- Faça um programa em C# que receba 3 notas, calcule a média aritmética e 
mostre na tela a média final e a situação do aluno 
Se o Aluno obtiver nota menor que 6, será reprovado. Caso contrário, ele será aprovado
*/

int [] notas = new int [3];
for(int i = 0; i < 3; i ++)
{
    Console.WriteLine(" Digite sua nota: ");
    notas[i] = int.Parse(Console.ReadLine());
}
    float media = (notas[0]+ notas[1]+ notas[2]) / 3 ; 
    Console.WriteLine(" Sua média: " + media);
    Console.ReadKey();

/*
2- Faça um programa em C# que receba a idade do usuário e mostre uma
 mensagem de acordo com as condições abaixo  
*/


Console.WriteLine("Digite sua idade");
int idade = int.Parse(Console.ReadLine());

if(idade < 18)
{
    Console.WriteLine("Você é menor de idade");
    Console.ReadKey();

}else if(idade >= 18 && idade <= 64 ){
    Console.WriteLine("Você está na flor da pela");
    Console.ReadKey();
} else if(idade >= 65){
    Console.WriteLine("Você está na melhor idade");
    Console.ReadKey();
}

/*3- Faça um programa em C# que receba a idade do usua´rio e mostre uma mensagem de acordo com 
a tabela abaixo*/

Console.WriteLine("Digite sua Altura:");
float altura = float.Parse(Console.ReadLine());
Console.WriteLine("Digite seu Peso em kg:");
float peso = float.Parse(Console.ReadLine());

float IMC =  peso /((altura * altura));

if(IMC < 18.5){
    Console.WriteLine($"Abaixo do Peso {IMC} ");
    Console.ReadKey();
}else if(IMC < 25){
    Console.WriteLine($"Peso Normal {IMC}");
    Console.ReadKey();
}else if(IMC < 30){
    Console.WriteLine($"Sobrepeso {IMC}");
    Console.ReadKey();
}else if(IMC < 35){
    Console.WriteLine($"Obsediade grau I {IMC}");
    Console.ReadKey();
}else if(IMC < 40){
    Console.WriteLine($"Obsediade grau II {IMC}");
    Console.ReadKey();
}else if(IMC >= 40){
    Console.WriteLine($"Obsediade grau III {IMC}");
    Console.ReadKey();
}
 

 /*4- Faça um programa em C# que simule uma urna eletronica*/
    Console.WriteLine("Digite [1]-Cadidato 1");
    Console.WriteLine("Digite [2]-Cadidato 2");
    Console.WriteLine("Digite [3]-Cadidato 3");
    int candidato  = int.Parse(Console.ReadLine());
 

 switch (candidato) {
    case 1: Console.WriteLine("Votou [1]-Cadidato 1"); break;
    case 2: Console.WriteLine("Votou [2]-Cadidato 2"); break;
    case 3: Console.WriteLine("Votou [3]-Cadidato 3"); break;
 }
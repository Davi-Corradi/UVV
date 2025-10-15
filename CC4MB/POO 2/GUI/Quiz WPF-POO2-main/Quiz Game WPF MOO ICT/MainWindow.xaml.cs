
using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Quiz_Game_WPF_MOO_ICT
{
    public partial class MainWindow : Window
    {
        public class Pergunta
        {
            public string Categoria { get; set; }
            public string Texto { get; set; }
            public string[] Alternativas { get; set; }
            public int RespostaCorreta { get; set; } // índice 0 a 3
            public string CaminhoImagem { get; set; }
        }

        List<Pergunta> todasPerguntas = new List<Pergunta>
        {
            // --- Geografia ---
            new Pergunta
            {
                Categoria = "Geografia",
                Texto = "Qual é a capital da França?",
                Alternativas = new[] { "Berlim", "Madrid", "Paris", "Lisboa" },
                RespostaCorreta = 2,
                CaminhoImagem = "pack://application:,,,/images/5.jpeg"
            },
            new Pergunta
            {
                Categoria = "Geografia",
                Texto = "Qual é o maior oceano do mundo?",
                Alternativas = new[] { "Atlântico", "Pacífico", "Índico", "Ártico" },
                RespostaCorreta = 1,
                CaminhoImagem = "pack://application:,,,/images/6.jpeg"
            },
            new Pergunta
            {
                Categoria = "Geografia",
                Texto = "Qual país tem a maior população do mundo?",
                Alternativas = new[] { "Índia", "Estados Unidos", "Brasil", "China" },
                RespostaCorreta = 3,
                CaminhoImagem = "pack://application:,,,/images/7.jpeg"
            },
            new Pergunta
            {
                Categoria = "Geografia",
                Texto = "Qual é a montanha mais alta do mundo?",
                Alternativas = new[] { "K2", "Everest", "Mont Blanc", "Aconcágua" },
                RespostaCorreta = 1,
                CaminhoImagem = "pack://application:,,,/images/8.jpeg"
            },

            // --- Matemática ---
            new Pergunta
            {
                Categoria = "Matemática",
                Texto = "Quanto é 9 x 7?",
                Alternativas = new[] { "63", "72", "56", "49" },
                RespostaCorreta = 0,
                CaminhoImagem = "pack://application:,,,/images/2.jpeg"
            },
            new Pergunta
            {
                Categoria = "Matemática",
                Texto = "Qual o valor de π arredondado para duas casas decimais?",
                Alternativas = new[] { "3.14", "3.15", "3.12", "3.16" },
                RespostaCorreta = 0,
                CaminhoImagem = "pack://application:,,,/images/1.png"
            },
            new Pergunta
            {
                Categoria = "Matemática",
                Texto = "Qual é a fórmula da área do círculo?",
                Alternativas = new[] { "2πr", "πr²", "πd", "r²" },
                RespostaCorreta = 1,
                CaminhoImagem = "pack://application:,,,/images/3.jpeg"
            },
            new Pergunta
            {
                Categoria = "Matemática",
                Texto = "Qual é o próximo número na sequência: 2, 4, 8, 16, ...?",
                Alternativas = new[] { "18", "24", "32", "30" },
                RespostaCorreta = 2,
                CaminhoImagem = "pack://application:,,,/images/4.png"
            },

            // --- Ciências ---
            new Pergunta
            {
                Categoria = "Ciência",
                Texto = "Qual é o elemento químico com símbolo O?",
                Alternativas = new[] { "Ouro", "Oxigênio", "Zinco", "Prata" },
                RespostaCorreta = 1,
                CaminhoImagem = "pack://application:,,,/images/9.jpg"
            },
            new Pergunta
            {
                Categoria = "Ciência",
                Texto = "Qual é o planeta mais próximo do Sol?",
                Alternativas = new[] { "Marte", "Vênus", "Mercúrio", "Terra" },
                RespostaCorreta = 2,
                CaminhoImagem = "pack://application:,,,/images/11.jpg"
            },
            new Pergunta
            {
                Categoria = "Ciência",
                Texto = "Qual destes é um mamífero?",
                Alternativas = new[] { "Cobra", "Tubarão", "Golfinho", "Papagaio" },
                RespostaCorreta = 2,
                CaminhoImagem = "pack://application:,,,/images/12.jpg"
            },
            new Pergunta
            {
                Categoria = "Ciência",
                Texto = "Qual a função dos glóbulos vermelhos no sangue?",
                Alternativas = new[] { "Defender contra infecções", "Transportar oxigênio", "Coagular sangue", "Produzir hormônios" },
                RespostaCorreta = 1,
                CaminhoImagem = "pack://application:,,,/images/13.jpeg"
            }
        };

        List<Pergunta> perguntasSelecionadas;
        int perguntaAtual = 0;
        int pontuacao = 0;

        public MainWindow()
        {
            InitializeComponent();

            // Categorias fixas
            var categorias = new List<string> { "Matemática", "Geografia", "Ciência" };
            categorySelector.ItemsSource = categorias;

            menuPanel.Visibility = Visibility.Visible;
            myCanvas.Visibility = Visibility.Collapsed;
        }

        private void StartGameFromCategory(object sender, RoutedEventArgs e)
        {
            if (categorySelector.SelectedItem == null)
            {
                MessageBox.Show("Por favor, selecione uma categoria!");
                return;
            }

            string categoria = categorySelector.SelectedItem.ToString();

            perguntasSelecionadas = todasPerguntas
                .Where(p => p.Categoria == categoria)
                .OrderBy(p => Guid.NewGuid()) // embaralhar
                .ToList();

            perguntaAtual = 0;
            pontuacao = 0;

            menuPanel.Visibility = Visibility.Collapsed;
            myCanvas.Visibility = Visibility.Visible;

            MostrarPergunta();
        }

        private void MostrarPergunta()
        {
            if (perguntaAtual >= perguntasSelecionadas.Count)
            {
                MessageBox.Show($"Fim do jogo! Pontuação: {pontuacao}/{perguntasSelecionadas.Count}");
                myCanvas.Visibility = Visibility.Collapsed;
                menuPanel.Visibility = Visibility.Visible;
                return;
            }

            var p = perguntasSelecionadas[perguntaAtual];

            txtQuestion.Text = p.Texto;
            ans1.Content = p.Alternativas[0];
            ans2.Content = p.Alternativas[1];
            ans3.Content = p.Alternativas[2];
            ans4.Content = p.Alternativas[3];

            qImage.Source = new BitmapImage(new Uri(p.CaminhoImagem));

            ans1.Tag = (p.RespostaCorreta == 0) ? "1" : "0";
            ans2.Tag = (p.RespostaCorreta == 1) ? "1" : "0";
            ans3.Tag = (p.RespostaCorreta == 2) ? "1" : "0";
            ans4.Tag = (p.RespostaCorreta == 3) ? "1" : "0";

            foreach (var x in myCanvas.Children.OfType<Button>())
                x.Background = Brushes.LightGray;

            scoreText.Content = $"Pontuação: {pontuacao}/{perguntasSelecionadas.Count}";
        }

        private void checkAnswer(object sender, RoutedEventArgs e)
        {
            Button clicked = sender as Button;

            if (clicked.Tag.ToString() == "1")
                pontuacao++;

            perguntaAtual++;
            MostrarPergunta();
        }
    }
}
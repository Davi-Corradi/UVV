using System.Diagnostics.Eventing.Reader;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using WpfApp1.control;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private IdeiaInovacaoControle objIIControle = new();
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            // Console.WriteLine("not chamar BD direto ");
            if (!string.IsNullOrEmpty(Area.Text) &&
                !string.IsNullOrEmpty(Ideia.Text))
            
                if (objIIControle.ControleCadastrarII(Area.Text,
                                              Ideia.Text,
                                              float.Parse(Custo.Text)))
                {
                Console.WriteLine("Cadastro Realizado com Sucesso! ");
                }
            else
            {
                Console.WriteLine("Erro ao cadastrar! ");
            }
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
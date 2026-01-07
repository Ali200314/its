using System.Security.Principal;
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
using System;
using System;

namespace Usikre_OP_Systemer
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            //DEL 1 - Tjek brugernavn
            var id = WindowsIdentity.GetCurrent();
            string current = id.Name;


            // Brug én backslash i verbatim string: @"PC\USER"
            bool isAllowedUser = string.Equals(current, @"DESKTOP-IIEBO8D\SF47",
                                               StringComparison.OrdinalIgnoreCase);

          

            //DEL 2 - Tjek om adminstratorrettigheder
            var principal = new WindowsPrincipal(id);

            bool isAdmin = principal.IsInRole(WindowsBuiltInRole.Administrator);

            // Print til frontend
            TxtCurrentUser.Text = current;
            TxtIsAllowed.Text = isAdmin ? "JA ✅" : "NEJ ❌";

            // (valgfrit) hvis ikke tilladt: luk
            //if (!isAllowedUser) Close();
        }
    }
}

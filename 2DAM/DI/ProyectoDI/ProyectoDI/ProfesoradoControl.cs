using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProyectoDI
{
    public partial class ProfesoradoControl : UserControl
    {
        int pagina = 1;
        public ProfesoradoControl()
        {
            InitializeComponent();
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            if (pagina==1)
            {
                panel1.Visible = false;
                panel2.Visible = false;
                panel3.Visible = false;
                panel4.Visible = false;

                panel5.Visible = true;
                panel6.Visible = true;
                panel7.Visible = true;

                pagina = 2;
            }
            else
            {
                panel1.Visible = true;
                panel2.Visible = true;
                panel3.Visible = true;
                panel4.Visible = true;

                panel5.Visible = false;
                panel6.Visible = false;
                panel7.Visible = false;

                pagina = 1;
            }
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            if (pagina == 1)
            {
                panel1.Visible = false;
                panel2.Visible = false;
                panel3.Visible = false;
                panel4.Visible = false;

                panel5.Visible = true;
                panel6.Visible = true;
                panel7.Visible = true;

                pagina = 2;
            }
            else
            {
                panel1.Visible = true;
                panel2.Visible = true;
                panel3.Visible = true;
                panel4.Visible = true;

                panel5.Visible = false;
                panel6.Visible = false;
                panel7.Visible = false;

                pagina = 1;
            }
        }
    }
}

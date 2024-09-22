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
    public partial class MapaControl : UserControl
    {
        int plano = 1;

        public MapaControl()
        {
            InitializeComponent();
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            if (plano==1)
            {
                pictureBox1.Visible = false;
                pictureBox2.Visible = true;
                plano = 2;
            }
            else if (plano == 2)
            {
                pictureBox2.Visible = false;
                pictureBox3.Visible = true;
                plano = 3;
            }
            else if (plano == 3)
            {
                pictureBox3.Visible = false;
                pictureBox4.Visible = true;
                plano = 4;
            }
            else if (plano == 4){
                pictureBox4.Visible = false;
                pictureBox1.Visible = true;
                plano = 1;
            }
        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {
            if (plano == 1)
            {
                pictureBox1.Visible = false;
                pictureBox4.Visible = true;
                plano = 4;
            }
            else if (plano == 2)
            {
                pictureBox2.Visible = false;
                pictureBox1.Visible = true;
                plano = 1;
            }
            else if (plano == 3)
            {
                pictureBox3.Visible = false;
                pictureBox2.Visible = true;
                plano = 2;
            }
            else if (plano == 4)
            {
                pictureBox4.Visible = false;
                pictureBox3.Visible = true;
                plano = 3;
            }
        }
    }
}

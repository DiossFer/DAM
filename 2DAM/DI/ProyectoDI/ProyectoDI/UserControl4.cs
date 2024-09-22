using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using Spire.PdfViewer.Forms;

namespace ProyectoDI
{
    public partial class UserControl4 : UserControl
    {
        String ruta;
        public UserControl4()
        {
            InitializeComponent();
            ruta = "calendario.pdf";
            if (File.Exists(ruta))
            {
                this.pdfDocumentViewer1.LoadFromFile(ruta);
            }
        }

        private void UserControl4_Load(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            panel2.Visible = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if ((textBox1.Text.Equals("admin"))&&(textBox2.Text.Equals("admin")))
            {
                panel1.Visible = true;
            }
            textBox1.Text = "";
            textBox2.Text = "";
            panel2.Visible=false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            panel1.Visible = false;
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Filter = "PDF document (*.pdf)|*.pdf";
            DialogResult result = dialog.ShowDialog();
            if (result == DialogResult.OK)
            {
                try {
                    String pdfFile = dialog.FileName;
                    this.pdfDocumentViewer1.LoadFromFile(pdfFile);

                }
                catch (Exception exc)
                {
                    MessageBox.Show("Error en el cargado del pdf");
                }
            }
        }
    }
}

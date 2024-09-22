using PdfiumViewer;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProyectoDI
{
    public partial class UserControl3 : UserControl
    {
        PdfiumViewer.PdfViewer pdf;
        String ruta = "calendario.pdf";

        public UserControl3()
        {
            InitializeComponent();
            pdf = new PdfViewer();
            this.Controls.Add(pdf);
            openfile(ruta);
        }

        private void UserControl3_Load(object sender, EventArgs e)
        {

            
        }

        public void openfile(string filepath)
        {
            byte[] bytes = System.IO.File.ReadAllBytes(filepath);
            var stream = new MemoryStream(bytes);
            PdfDocument pdfDocument = PdfDocument.Load(stream);
            pdf.Document = pdfDocument;
        }
        public void cambiarRuta()
        {

            OpenFileDialog dialog = new OpenFileDialog();
            ruta = dialog.FileName;
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                openfile(ruta);
            }

        }
    }
}

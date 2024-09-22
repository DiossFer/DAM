using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using PdfiumViewer;
using System.IO;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Window;

namespace ProyectoDI
{

    public partial class CalendarioControl : UserControl
    {
        PdfiumViewer.PdfViewer pdf;
        String ruta = "calendario.pdf";

        public CalendarioControl()
        {
            InitializeComponent();
            pdf = new PdfViewer();
            this.Controls.Add(pdf);
        }

        private void CalendarioControl_Load(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            
            openfile(ruta);
            
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

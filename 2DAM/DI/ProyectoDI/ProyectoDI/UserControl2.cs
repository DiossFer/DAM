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
    public partial class UserControl2 : UserControl
    {
        public UserControl2()
        {
            InitializeComponent();
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            try
            {
                System.Net.Mail.MailMessage mnsg = new System.Net.Mail.MailMessage();

                mnsg.To.Add("sugerencias@cescristorey.com");
                mnsg.Subject = textBox3.Text;
                mnsg.SubjectEncoding = System.Text.Encoding.UTF8;

                mnsg.Body = textBox4.Text;
                mnsg.IsBodyHtml = true;
                mnsg.From = new System.Net.Mail.MailAddress(textBox1.Text);

                System.Net.Mail.SmtpClient cliente = new System.Net.Mail.SmtpClient();
                cliente.Credentials = new System.Net.NetworkCredential(textBox1.Text, textBox2.Text);

                cliente.Port = 587;
                cliente.EnableSsl = true;

                cliente.Host = "smtp.gmail.com";

                cliente.Send(mnsg);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error al enviar el mensaje");
            }

        }
    }
}

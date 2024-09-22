using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ahorcado
{
    public partial class Form1 : Form
    {
        private int vidas;
        private ArrayList palabras;
        private string palabra;

        public Form1()
        {
            InitializeComponent();
            vidas = 7;
            pictureBox1.Visible = true;
            palabras = new ArrayList();

            //Palabras iniciales
            cargarPalabrasIni();

            //Inicio
            muneco.Visible = false;
            panel1.Visible = false;
            panel2.Visible = false;

            if (palabras.Count > 0 )
            {
                domainUpDown1.SelectedIndex = 0;
            }
            


        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }



        private void label2_Click(object sender, EventArgs e)
        {

        }
        public void mostrarPartida()
        {
            salirPartida.Visible = true;

            muneco.Visible = true;
            panel1.Visible = true;
            panel2.Visible = true;
            panel3.Visible = false;
            admin.Visible = false;

            button1.Enabled = true;
            button2.Enabled = true;
            button3.Enabled = true;
            button4.Enabled = true;
            button5.Enabled = true;
            button6.Enabled = true;
            button7.Enabled = true;
            button8.Enabled = true;
            button9.Enabled = true;
            button10.Enabled = true;
            button11.Enabled = true;
            button12.Enabled = true;
            button13.Enabled = true;
            button14.Enabled = true;
            button15.Enabled = true;
            button16.Enabled = true;
            button17.Enabled = true;
            button18.Enabled = true;
            button19.Enabled = true;
            button20.Enabled = true;
            button21.Enabled = true;
            button22.Enabled = true;
            button23.Enabled = true;
            button24.Enabled = true;
            button25.Enabled = true;
            button26.Enabled = true;
            button27.Enabled = true;

            label1.Visible = false;
            label2.Visible = false;
            label3.Visible = false;
            label4.Visible = false;
            label5.Visible = false;
            label6.Visible = false;
            label7.Visible = false;
            label8.Visible = false;
            label9.Visible = false;
            label10.Visible = false;
            label11.Visible = false;
            label12.Visible = false;
            label13.Visible = false;
            label14.Visible = false;
            label15.Visible = false;
            label16.Visible = false;
            label17.Visible = false;
            label18.Visible = false;
            label19.Visible = false;
            label20.Visible = false;
            label21.Visible = false;
            label22.Visible = false;
            label23.Visible = false;
            label24.Visible = false;

            vidas = 7;

            pictureBox1.Visible = true;
            pictureBox2.Visible = false;
            pictureBox3.Visible = false;
            pictureBox4.Visible = false;
            pictureBox5.Visible = false;
            pictureBox6.Visible = false;
            pictureBox7.Visible = false;
            pictureBox8.Visible = false;

            label26.Text = "7 / 7";



            cargarPalabra();
        }
        public void menu()
        {
            salirPartida.Visible = false;
            muneco.Visible = false;
            panel1.Visible = false;
            panel2.Visible = false;
            panel3.Visible = true;
            admin.Visible = true;

        }

        public void ajustarModo(int modo)
        {

            char letra1 = ' ';
            char letra2 = ' ';
            int num;
            Random r = new Random();

            if (modo == 0)
            {

            }
            else if (modo == 1)
            {
                num = r.Next(0, palabra.Length);

                letra1 = palabra[num];

                pulsarTecla(letra1);
                actualizarTeclado(letra1);
            }
            else if (modo == 2)
            {
                bool cont = true;

                num = r.Next(0, palabra.Length);
                letra1 = palabra[num];

                while (cont)
                {
                    num = r.Next(0, palabra.Length);
                    letra2 = palabra[num];
                    if (!letra2.Equals(letra1))
                    {
                        cont = false;
                    }
                }
                pulsarTecla(letra1);
                actualizarTeclado(letra1);
                pulsarTecla(letra2);
                actualizarTeclado(letra2);
            }



        }

        public void actualizarTeclado(char c)
        {
            if (button1.Text[0].Equals(c))
            {
                button1.Enabled = false;
            }
            else if (button2.Text[0].Equals(c))
            {
                button2.Enabled = false;
            }
            else if (button3.Text[0].Equals(c))
            {
                button3.Enabled = false;
            }
            else if (button4.Text[0].Equals(c))
            {
                button4.Enabled = false;
            }
            else if (button5.Text[0].Equals(c))
            {
                button5.Enabled = false;
            }
            else if (button6.Text[0].Equals(c))
            {
                button6.Enabled = false;
            }
            else if (button7.Text[0].Equals(c))
            {
                button7.Enabled = false;
            }
            else if (button8.Text[0].Equals(c))
            {
                button8.Enabled = false;
            }
            else if (button9.Text[0].Equals(c))
            {
                button9.Enabled = false;
            }
            else if (button10.Text[0].Equals(c))
            {
                button10.Enabled = false;
            }
            else if (button11.Text[0].Equals(c))
            {
                button11.Enabled = false;
            }
            else if (button12.Text[0].Equals(c))
            {
                button12.Enabled = false;
            }
            else if (button13.Text[0].Equals(c))
            {
                button13.Enabled = false;
            }
            else if (button14.Text[0].Equals(c))
            {
                button14.Enabled = false;
            }
            else if (button15.Text[0].Equals(c))
            {
                button15.Enabled = false;
            }
            else if (button16.Text[0].Equals(c))
            {
                button16.Enabled = false;
            }
            else if (button17.Text[0].Equals(c))
            {
                button17.Enabled = false;
            }
            else if (button18.Text[0].Equals(c))
            {
                button18.Enabled = false;
            }
            else if (button19.Text[0].Equals(c))
            {
                button19.Enabled = false;
            }
            else if (button20.Text[0].Equals(c))
            {
                button20.Enabled = false;
            }
            else if (button21.Text[0].Equals(c))
            {
                button21.Enabled = false;
            }
            else if (button22.Text[0].Equals(c))
            {
                button22.Enabled = false;
            }
            else if (button23.Text[0].Equals(c))
            {
                button23.Enabled = false;
            }
            else if (button24.Text[0].Equals(c))
            {
                button24.Enabled = false;
            }
            else if (button25.Text[0].Equals(c))
            {
                button25.Enabled = false;
            }
            else if (button26.Text[0].Equals(c))
            {
                button26.Enabled = false;
            }
            else if (button27.Text[0].Equals(c))
            {
                button27.Enabled = false;
            }
        }

        public void cargarPalabra()
        {
            Random r = new Random();
            int num = r.Next(0, palabras.Count);
            palabra = (string)palabras[num];

            int i = 0;
            foreach (char c in palabra)
            {
                i++;
                if (!c.Equals(' '))
                {



                    if (i == 1)
                    {
                        label1.Visible = true;


                    }
                    else if (i == 2)
                    {
                        label2.Visible = true;

                    }
                    else if (i == 3)
                    {
                        label3.Visible = true;

                    }
                    else if (i == 4)
                    {
                        label4.Visible = true;

                    }
                    else if (i == 5)
                    {
                        label5.Visible = true;


                    }
                    else if (i == 6)
                    {
                        label6.Visible = true;

                    }
                    else if (i == 7)
                    {
                        label7.Visible = true;

                    }
                    else if (i == 8)
                    {
                        label8.Visible = true;

                    }
                    else if (i == 9)
                    {
                        label9.Visible = true;

                    }
                    else if (i == 10)
                    {
                        label10.Visible = true;

                    }
                    else if (i == 11)
                    {
                        label11.Visible = true;

                    }
                    else if (i == 12)
                    {
                        label12.Visible = true;

                    }
                }
            }
        }

        public bool comprobarLetra(char letra)
        {
            bool esta = false;

            foreach (char c in palabra)
            {
                if (letra.Equals(c))
                {
                    esta = true;
                }
            }

            return esta;
        }

        public void ActualizarPalabra(char letra)
        {
            int i = 0;
            foreach (char l in palabra)
            {
                i++;
                if (l.Equals(letra))
                {
                    if (i == 1)
                    {
                        label13.Text = l.ToString();
                        label13.Visible = true;

                    }
                    else if (i == 2)
                    {
                        label14.Text = l.ToString();
                        label14.Visible = true;
                    }
                    else if (i == 3)
                    {

                        label15.Text = l.ToString();
                        label15.Visible = true;

                    }
                    else if (i == 4)
                    {
                        label16.Text = l.ToString();
                        label16.Visible = true;
                    }
                    else if (i == 5)
                    {
                        label17.Text = l.ToString();
                        label17.Visible = true;

                    }
                    else if (i == 6)
                    {
                        label18.Text = l.ToString();
                        label18.Visible = true;
                    }
                    else if (i == 7)
                    {
                        label19.Text = l.ToString();
                        label19.Visible = true;
                    }
                    else if (i == 8)
                    {
                        label20.Text = l.ToString();
                        label20.Visible = true;
                    }
                    else if (i == 9)
                    {
                        label21.Text = l.ToString();
                        label21.Visible = true;
                    }
                    else if (i == 10)
                    {
                        label22.Text = l.ToString();
                        label22.Visible = true;
                    }
                    else if (i == 11)
                    {
                        label23.Text = l.ToString();
                        label23.Visible = true;
                    }
                    else if (i == 12)
                    {
                        label24.Text = l.ToString();
                        label24.Visible = true;
                    }
                }
            }



        }

        public void QuitarVida()
        {
            vidas--;

            label26.Text = vidas.ToString() + " / 7";
            if (vidas == 6)
            {
                pictureBox1.Visible = false;
                pictureBox2.Visible = true;

            }
            else if (vidas == 5)
            {
                pictureBox2.Visible = false;
                pictureBox3.Visible = true;
            }
            else if (vidas == 4)
            {
                pictureBox3.Visible = false;
                pictureBox4.Visible = true;
            }
            else if (vidas == 3)
            {
                pictureBox4.Visible = false;
                pictureBox8.Visible = true;
            }
            else if (vidas == 2)
            {
                pictureBox8.Visible = false;
                pictureBox5.Visible = true;
            }

            else if (vidas == 1)
            {
                pictureBox5.Visible = false;
                pictureBox6.Visible = true;
            }
            else if (vidas == 0)
            {
                pictureBox6.Visible = false;
                pictureBox7.Visible = true;
            }


        }

        public bool comprobarWIN()
        {
            bool win = true;

            if (!(label13.Visible == true || label1.Visible == false))
            {
                win = false;
            }
            else if (!(label14.Visible == true || label2.Visible == false))
            {
                win = false;
            }
            else if (!(label15.Visible == true || label3.Visible == false))
            {
                win = false;
            }
            else if (!(label16.Visible == true || label4.Visible == false))
            {
                win = false;
            }
            else if (!(label17.Visible == true || label5.Visible == false))
            {
                win = false;
            }
            else if (!(label18.Visible == true || label6.Visible == false))
            {
                win = false;
            }
            else if (!(label19.Visible == true || label7.Visible == false))
            {
                win = false;
            }
            else if (!(label20.Visible == true || label8.Visible == false))
            {
                win = false;
            }
            else if (!(label21.Visible == true || label9.Visible == false))
            {
                win = false;
            }
            else if (!(label22.Visible == true || label10.Visible == false))
            {
                win = false;
            }
            else if (!(label23.Visible == true || label11.Visible == false))
            {
                win = false;
            }
            else if (!(label24.Visible == true || label12.Visible == false))
            {
                win = false;
            }

            return win;
        }
        public bool comprobarLOSE()
        {
            bool lose = false;
            if (vidas == 0)
            {
                lose = true;
            }
            return lose;
        }


        public void pulsarTecla(char c)
        {
            if (comprobarLetra(c))
            {
                ActualizarPalabra(c);
            }
            else
            {
                QuitarVida();
            }
            if (comprobarLOSE())
            {
                MessageBox.Show("Buen intento pero no lograste hallar la palabra, esta era " + palabra, "DERROTA", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                menu();
            }
            else
            {
                if (comprobarWIN())
                {
                    MessageBox.Show("Felicidades has ganado, la palabra era " + palabra, "VICTORIA", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    menu();
                }
            }

        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

        private void button28_Click(object sender, EventArgs e)
        {
            panel4.Visible = true;
            admin.Visible = false;
            panel3.Visible = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            button1.Enabled = false;
            pulsarTecla(button1.Text[0]);

        }
        private void Button2_Click(object sender, EventArgs e)
        {
            button2.Enabled = false;

            pulsarTecla(button2.Text[0]);

        }

        private void button3_Click(object sender, EventArgs e)
        {
            button3.Enabled = false;

            pulsarTecla(button3.Text[0]);

        }

        private void button4_Click(object sender, EventArgs e)
        {
            button4.Enabled = false;

            pulsarTecla(button4.Text[0]);

        }

        private void button5_Click(object sender, EventArgs e)
        {
            button5.Enabled = false;

            pulsarTecla(button5.Text[0]);

        }

        private void button6_Click(object sender, EventArgs e)
        {
            button6.Enabled = false;

            pulsarTecla(button6.Text[0]);

        }

        private void button7_Click(object sender, EventArgs e)
        {
            button7.Enabled = false;

            pulsarTecla(button7.Text[0]);

        }

        private void button8_Click(object sender, EventArgs e)
        {
            button8.Enabled = false;

            pulsarTecla(button8.Text[0]);

        }

        private void button9_Click(object sender, EventArgs e)
        {
            button9.Enabled = false;

            pulsarTecla(button9.Text[0]);

        }

        private void button10_Click(object sender, EventArgs e)
        {
            button10.Enabled = false;

            pulsarTecla(button10.Text[0]);

        }

        private void button11_Click(object sender, EventArgs e)
        {
            button11.Enabled = false;

            pulsarTecla(button11.Text[0]);

        }

        private void button12_Click(object sender, EventArgs e)
        {
            button12.Enabled = false;

            pulsarTecla(button12.Text[0]);

        }

        private void button13_Click(object sender, EventArgs e)
        {
            button13.Enabled = false;

            pulsarTecla(button13.Text[0]);

        }

        private void button14_Click(object sender, EventArgs e)
        {
            button14.Enabled = false;

            pulsarTecla(button14.Text[0]);

        }

        private void button15_Click(object sender, EventArgs e)
        {
            button15.Enabled = false;

            pulsarTecla(button15.Text[0]);

        }

        private void button16_Click(object sender, EventArgs e)
        {
            button16.Enabled = false;

            pulsarTecla(button16.Text[0]);

        }

        private void button17_Click(object sender, EventArgs e)
        {
            button17.Enabled = false;

            pulsarTecla(button17.Text[0]);

        }

        private void button18_Click(object sender, EventArgs e)
        {
            button18.Enabled = false;

            pulsarTecla(button18.Text[0]);

        }

        private void button19_Click(object sender, EventArgs e)
        {
            button19.Enabled = false;

            pulsarTecla(button19.Text[0]);

        }

        private void button20_Click(object sender, EventArgs e)
        {
            button20.Enabled = false;

            pulsarTecla(button20.Text[0]);

        }

        private void button21_Click(object sender, EventArgs e)
        {
            button21.Enabled = false;

            pulsarTecla(button21.Text[0]);

        }

        private void button22_Click(object sender, EventArgs e)
        {
            button22.Enabled = false;

            pulsarTecla(button22.Text[0]);

        }

        private void button23_Click(object sender, EventArgs e)
        {
            button23.Enabled = false;

            pulsarTecla(button23.Text[0]);

        }

        private void button24_Click(object sender, EventArgs e)
        {
            button24.Enabled = false;

            pulsarTecla(button24.Text[0]);

        }

        private void button25_Click(object sender, EventArgs e)
        {
            button25.Enabled = false;

            pulsarTecla(button25.Text[0]);

        }

        private void button26_Click(object sender, EventArgs e)
        {
            button26.Enabled = false;

            pulsarTecla(button26.Text[0]);

        }

        private void button27_Click(object sender, EventArgs e)
        {
            button27.Enabled = false;

            pulsarTecla(button27.Text[0]);

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label16_Click(object sender, EventArgs e)
        {

        }

        private void button29_Click(object sender, EventArgs e)
        {
            if (palabras.Count != 0)
            {
                mostrarPartida();
                ajustarModo(2);
            }
            else
            {
                MessageBox.Show("No hay palabras cargadas, solicite al administrador que añade nuevas" + palabra, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);

            }

        }

        private void button30_Click(object sender, EventArgs e)
        {
            if (palabras.Count != 0)
            {
                mostrarPartida();
                ajustarModo(1);
            }
            else
            {
                MessageBox.Show("No hay palabras cargadas, solicite al administrador que añade nuevas" + palabra, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);

            }

        }

        private void button31_Click(object sender, EventArgs e)
        {
            if (palabras.Count != 0)
            {
                mostrarPartida();
                ajustarModo(0);
            }
            else
            {
                MessageBox.Show("No hay palabras cargadas, solicite al administrador que añade nuevas" + palabra, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);

            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button32_Click(object sender, EventArgs e)
        {
            panel3.Visible = true;
            admin.Visible = true;
            panel4.Visible = false;
            textBox1.Text = "";
            textBox2.Text = "";


        }

        private void button28_Click_1(object sender, EventArgs e)
        {
            if (textBox1.Text == "admin" && textBox2.Text == "1234")
            {
                textBox1.Text = "";
                textBox2.Text = "";
                panel5.Visible = true;
                panel4.Visible = false;
                button34.Visible = true;
            }
            else
            {
                textBox1.Text = "";
                textBox2.Text = "";
                MessageBox.Show("Usuario o contraseña no valido", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);

            }
        }

        private void button34_Click(object sender, EventArgs e)
        {
            panel5.Visible = false;
            panel4.Visible = false;
            button34.Visible = false;
            textBox3.Text = "";
            menu();
        }

        private void button33_Click(object sender, EventArgs e)
        {
            String pal;
            bool valido = false;

            pal = textBox3.Text.Trim();
            pal = pal.ToUpper();

            char c1 = ' ';
            char c2 = ' ';
            char c3 = ' ';

            int i = 0;


            foreach (char c in pal)
            {
                i++;

                if (i == 1)
                {
                    c1 = c;
                }
                else if (c2.Equals(' ') && !c.Equals(c1) && !c.Equals(' '))
                {
                    c2 = c;
                }
                else if (!c2.Equals(' ') && !c.Equals(' ') && !c.Equals(c1) && !c.Equals(c2))
                {
                    c3 = c;
                }
            }

            //Las palabras deben de contener tres letras minimo para que se pueda usar en cada modo
            if (!c1.Equals(' ') && !c2.Equals(' ') && !c3.Equals(' '))
            {
                valido = true;
            }


            //No debe de superar las 12 letras
            if (pal.Length > 12)
            {
                valido = false;
            }



            //Ahora filtrada la agregamos
            if (valido)
            {
                bool condicion = true;

                foreach (String p in palabras)
                {
                    if (pal.Equals(p))
                    {
                        condicion = false;
                    }
                }
                if (condicion)
                {
                    palabras.Add(pal);
                    domainUpDown1.Items.Add(pal);
                    textBox3.Text = "";
                    domainUpDown1.SelectedIndex = 0;

                    //Guardamos en el fichero
                    guardarContenidoFichero();
                }
                else
                {
                    MessageBox.Show("La palabra \"" + pal + "\" ya esta incluida en el sistema", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);

                }

            }
            else
            {
                MessageBox.Show("Palabra no valida, asegurese de superar las tres letras diferentes y de no superar los 12 caracteres" + palabra, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);

            }
        }

        private void button35_Click(object sender, EventArgs e)
        {
            if (domainUpDown1.Items.Count != 0)
            {

                int i = 0;
                i = domainUpDown1.Items.IndexOf(domainUpDown1.Text);
                domainUpDown1.Items.Remove(domainUpDown1.Items[i]);
                palabras.Remove(palabras[i]);

                if (domainUpDown1.Items.Count != 0)
                {
                    domainUpDown1.SelectedIndex = 0;
                }
                else
                {
                    domainUpDown1.Text = "";
                }

                guardarContenidoFichero();

            }
        }
        public void guardarContenidoFichero()
        {

            using (StreamWriter escritor = new StreamWriter("palabras.txt"))
            {
                string contenido = "";
                for (int i = 0; i < palabras.Count; i++)
                {
                    contenido += palabras[i];
                    if (i != palabras.Count - 1)
                    {
                        contenido += ", ";
                    }
                }


                escritor.WriteLine(contenido);
            }
        }
        public void cargarPalabrasIni()
        {
            using (StreamReader lector = new StreamReader("palabras.txt"))
            {
                string contenido = lector.ReadLine();

                if (contenido != null)
                {
                    foreach (string pal in contenido.Split(new string[] { ", " }, StringSplitOptions.None))
                    {
                        palabras.Add(pal);
                        domainUpDown1.Items.Add(pal);
                    }
                }
            }
        }

        private void salirPartida_Click(object sender, EventArgs e)
        {
            menu();
        }
    }
    
}
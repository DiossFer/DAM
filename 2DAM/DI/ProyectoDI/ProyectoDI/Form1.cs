using GMap.NET;
using GMap.NET.MapProviders;
using GMap.NET.WindowsForms;
using GMap.NET.WindowsForms.Markers;
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
    public partial class Form1 : Form
    {
        GMarkerGoogle marker;
        GMapOverlay markerOverlay;

        public Form1()
        {
            InitializeComponent();

            gMapControl1.MapProvider = GMapProviders.GoogleMap;
            gMapControl1.Position = new PointLatLng(37.184281291532784, -3.593371358408752);
            gMapControl1.MinZoom = 10;
            gMapControl1.MaxZoom = 24;
            gMapControl1.Zoom = 9;
            gMapControl1.AutoScroll = true;

            //Marcador
            markerOverlay = new GMapOverlay("Marcador");
            marker = new GMarkerGoogle (new PointLatLng(37.184281291532784, -3.593371358408752), GMarkerGoogleType.green);
            markerOverlay.Markers.Add(marker);

            // agregamos tooltip
            marker.ToolTipMode = MarkerTooltipMode.Always;
            marker.ToolTipText = string.Format("Cristo Rey");

            //Lo agregamos
            gMapControl1.Overlays.Add(markerOverlay);

            //Marcador
            markerOverlay = new GMapOverlay("Marcador");
            marker = new GMarkerGoogle(new PointLatLng(37.18125213449758, -3.592659472636711), GMarkerGoogleType.blue);
            markerOverlay.Markers.Add(marker);

            // agregamos tooltip
            marker.ToolTipMode = MarkerTooltipMode.Always;
            marker.ToolTipText = string.Format("Mirador de san Nicolas");

            //Lo agregamos
            gMapControl1.Overlays.Add(markerOverlay);


            //Marcador
            markerOverlay = new GMapOverlay("Marcador");
            marker = new GMarkerGoogle(new PointLatLng(37.18310695204097, -3.5959986504655235), GMarkerGoogleType.blue);
            markerOverlay.Markers.Add(marker);

            // agregamos tooltip
            marker.ToolTipMode = MarkerTooltipMode.Always;
            marker.ToolTipText = string.Format("Mirador de san Cristobal");

            //Lo agregamos
            gMapControl1.Overlays.Add(markerOverlay);

            //Marcador
            markerOverlay = new GMapOverlay("Marcador");
            marker = new GMarkerGoogle(new PointLatLng(37.18408144145909, -3.5960021120580685), GMarkerGoogleType.blue);
            markerOverlay.Markers.Add(marker);

            // agregamos tooltip
            marker.ToolTipMode = MarkerTooltipMode.Always;
            marker.ToolTipText = string.Format("El Pepe (cafeteria popular)");

            //Lo agregamos
            gMapControl1.Overlays.Add(markerOverlay);

            //Marcador
            markerOverlay = new GMapOverlay("Marcador");
            marker = new GMarkerGoogle(new PointLatLng(37.18360964668061, -3.592772254715105), GMarkerGoogleType.blue);
            markerOverlay.Markers.Add(marker);

            // agregamos tooltip
            marker.ToolTipMode = MarkerTooltipMode.Always;
            marker.ToolTipText = string.Format("Elemen (Super Mercado Popular)");

            //Lo agregamos
            gMapControl1.Overlays.Add(markerOverlay);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            sidePanel.Height = button1.Height;
            sidePanel.Top = button1.Top;
            bienvenidaControl1.BringToFront();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            sidePanel.Height = button2.Height;
            sidePanel.Top = button2.Top;
            profesoradoControl1.BringToFront();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            sidePanel.Height = button3.Height;
            sidePanel.Top = button3.Top;
            mapaControl1.BringToFront();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            sidePanel.Height = button4.Height;
            sidePanel.Top = button4.Top;
            userControl11.BringToFront();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            sidePanel.Height = button5.Height;
            sidePanel.Top = button5.Top;
            gMapControl1.BringToFront();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            sidePanel.Height = button6.Height;
            sidePanel.Top = button6.Top;
            userControl21.BringToFront();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            sidePanel.Height = button8.Height;
            sidePanel.Top = button8.Top;
            userControl41.BringToFront();
        }
    }
}

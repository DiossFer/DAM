package com.example.calculadora;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

// Fernando Ortega Castro

public class MainActivity extends AppCompatActivity {

    TextView actual;
    TextView anterior;

    Button c;
    Button cambiarSigno;
    Button porcentaje;
    Button div;
    Button prod;
    Button menos;
    Button suma;
    Button igual;
    Button ceroCero;
    Button punto;

    Button cero;
    Button uno;
    Button dos;
    Button tres;
    Button cuatro;
    Button cinco;
    Button seis;
    Button siete;
    Button ocho;
    Button nueve;

    Double actualDouble;
    Double anteriorDouble;
    String operacionAnterior;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        actual = findViewById(R.id.actual);
        anterior = findViewById(R.id.anterior);

        actualDouble = 0.0;
        anteriorDouble = 0.0;
        operacionAnterior = "";

        c = findViewById(R.id.c);
        cambiarSigno = findViewById(R.id.cambiarSigno);
        porcentaje = findViewById(R.id.modulo);
        div = findViewById(R.id.div);
        prod = findViewById(R.id.prod);
        menos = findViewById(R.id.menos);
        suma = findViewById(R.id.mas);
        igual = findViewById(R.id.igual);
        ceroCero = findViewById(R.id.ceroCero);
        punto = findViewById(R.id.punto);

        cero = findViewById(R.id.cero);
        uno = findViewById(R.id.uno);
        dos = findViewById(R.id.dos);
        tres = findViewById(R.id.tres);
        cuatro = findViewById(R.id.cuatro);
        cinco = findViewById(R.id.cinco);
        seis = findViewById(R.id.seis);
        siete = findViewById(R.id.siete);
        ocho = findViewById(R.id.ocho);
        nueve = findViewById(R.id.nueve);

        cero.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                actual.setText(actual.getText().toString() + "0");
            }
        });

        uno.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    actual.setText(actual.getText().toString() + "1");
            }
        });

        dos.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    actual.setText(actual.getText().toString() + "2");
            }
        });

        tres.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    actual.setText(actual.getText().toString() + "3");
            }
        });

        cuatro.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    actual.setText(actual.getText().toString() + "4");
            }
        });

        cinco.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    actual.setText(actual.getText().toString() + "5");
            }
        });

        seis.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    actual.setText(actual.getText().toString() + "6");
            }
        });

        siete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    actual.setText(actual.getText().toString() + "7");
            }
        });

        ocho.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    actual.setText(actual.getText().toString() + "8");
            }
        });

        nueve.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    actual.setText(actual.getText().toString() + "9");
            }
        });

        c.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                actual.setText("");
                anterior.setText("");
                operacionAnterior = "";
                actualDouble = 0.0;
                anteriorDouble = 0.0;
            }
        });

        ceroCero.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                actual.setText(actual.getText().toString() + "00");
            }
        });

        suma.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                // Casuistica 1 arriba vacio y abajo vacio
                if (anterior.getText().toString().equals("") && actual.getText().toString().equals("")) {
                    //No pasa nada
                }
                //Casuistica 2 arriba con cuenta anterior, abajo nada
                else if (actual.getText().toString().equals("")) {
                    anterior.setText(anterior.getText().toString().substring(0, anterior.getText().toString().length() - 3) + " + ");
                    operacionAnterior = "+";
                }
                //Casuistica 3 arriba vacio
                else if (anterior.getText().toString().equals("")) {
                    anterior.setText(actual.getText().toString() + " + ");
                    anteriorDouble = Double.parseDouble(actual.getText().toString());
                    actualDouble = 0.0;
                    actual.setText("");
                    operacionAnterior = "+";
                }
                //Casuistica 4 ambos con numero
                else {
                    actualDouble = Double.parseDouble(actual.getText().toString());
                    anteriorDouble = cuentacargada();
                    anterior.setText(Double.toString(anteriorDouble));
                    comprobarPunto0up();
                    anterior.setText(anterior.getText().toString() + " + ");
                    operacionAnterior="+";
                    actualDouble = 0.0;
                    actual.setText("");
                }
            }
        });
        menos.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                // Casuistica 1 arriba vacio y abajo vacio
                if (anterior.getText().toString().equals("") && actual.getText().toString().equals("")) {
                    //No pasa nada
                }
                //Casuistica 2 arriba con cuenta anterior, abajo nada
                else if (actual.getText().toString().equals("")) {
                    anterior.setText(anterior.getText().toString().substring(0, anterior.getText().toString().length() - 3) + " - ");
                    operacionAnterior = "-";
                }
                //Casuistica 3 arriba vacio
                else if (anterior.getText().toString().equals("")) {

                    anterior.setText(actual.getText().toString() + " - ");
                    anteriorDouble = Double.parseDouble(actual.getText().toString());

                    actualDouble = 0.0;
                    actual.setText("");

                    operacionAnterior = "-";

                }
                //Casuistica 4 ambos con numero
                else {
                    actualDouble = Double.parseDouble(actual.getText().toString());
                    anteriorDouble = cuentacargada();
                    anterior.setText(Double.toString(anteriorDouble));
                    comprobarPunto0up();
                    anterior.setText(anterior.getText().toString() + " - ");
                    operacionAnterior="-";
                    actualDouble = 0.0;
                    actual.setText("");

                }
            }
        });
        prod.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                // Casuistica 1 arriba vacio y abajo vacio
                if (anterior.getText().toString().equals("") && actual.getText().toString().equals("")) {
                    //No pasa nada
                }
                //Casuistica 2 arriba con cuenta anterior, abajo nada
                else if (actual.getText().toString().equals("")) {
                    anterior.setText(anterior.getText().toString().substring(0, anterior.getText().toString().length() - 3) + " X ");
                    operacionAnterior = "X";
                }
                //Casuistica 3 arriba vacio
                else if (anterior.getText().toString().equals("")) {

                    anterior.setText(actual.getText().toString() + " X ");
                    anteriorDouble = Double.parseDouble(actual.getText().toString());

                    actualDouble = 0.0;
                    actual.setText("");

                    operacionAnterior = "X";

                }
                //Casuistica 4 ambos con numero
                else {
                    actualDouble = Double.parseDouble(actual.getText().toString());
                    anteriorDouble = cuentacargada();
                    anterior.setText(Double.toString(anteriorDouble));
                    comprobarPunto0up();
                    anterior.setText(anterior.getText().toString() + " X ");
                    operacionAnterior="X";
                    actualDouble = 0.0;
                    actual.setText("");

                }
            }

        });
        div.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                // Casuistica 1 arriba vacio y abajo vacio
                if (anterior.getText().toString().equals("") && actual.getText().toString().equals("")) {
                    //No pasa nada
                }
                //Casuistica 2 arriba con cuenta anterior, abajo nada
                else if (actual.getText().toString().equals("")) {
                    anterior.setText(anterior.getText().toString().substring(0, anterior.getText().toString().length() - 3) + " ÷ ");
                    operacionAnterior = "÷";
                }
                //Casuistica 3 arriba vacio
                else if (anterior.getText().toString().equals("")) {

                    anterior.setText(actual.getText().toString() + " ÷ ");
                    anteriorDouble = Double.parseDouble(actual.getText().toString());

                    actualDouble = 0.0;
                    actual.setText("");

                    operacionAnterior = "÷";

                }
                //Casuistica 4 ambos con numero
                else {
                    actualDouble = Double.parseDouble(actual.getText().toString());
                    anteriorDouble = cuentacargada();
                    anterior.setText(Double.toString(anteriorDouble));
                    comprobarPunto0up();
                    anterior.setText(anterior.getText().toString() + " ÷ ");
                    operacionAnterior="÷";
                    actualDouble = 0.0;
                    actual.setText("");

                }
            }

        });
        porcentaje.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                // Casuistica 1 arriba vacio y abajo vacio
                if (anterior.getText().toString().equals("") && actual.getText().toString().equals("")) {
                    //No pasa nada
                }
                //Casuistica 2 arriba con cuenta anterior, abajo nada
                else if (actual.getText().toString().equals("")) {

                    actual.setText(anterior.getText().toString().substring(0, anterior.getText().toString().length()-3));
                    actualDouble=Double.parseDouble(actual.getText().toString());
                    actualDouble=actualDouble/100;
                    actual.setText(Double.toString(actualDouble));
                    anteriorDouble=0.0;
                    anterior.setText("");
                    operacionAnterior = "";

                }
                //Casuistica 3 arriba vacio
                else if (anterior.getText().toString().equals("")) {

                    actualDouble=Double.parseDouble(actual.getText().toString());
                    actualDouble=actualDouble/100;
                    actual.setText(Double.toString(actualDouble));
                    comprobarPunto0();

                }
                //Casuistica 4 ambos con numero
                else {
                    actualDouble = Double.parseDouble(actual.getText().toString());
                    actualDouble=actualDouble/100;
                    actual.setText(Double.toString(actualDouble));
                    comprobarPunto0();
                }
            }

        });

        cambiarSigno.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (!actual.getText().toString().equals("")){
                    actualDouble = Double.parseDouble(actual.getText().toString());
                    actual.setText(String.valueOf(actualDouble * (-1)));
                    comprobarPunto0();
                }
            }
        });
        igual.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                // Casuistica 1 arriba vacio y abajo vacio
                if (anterior.getText().toString().equals("") && actual.getText().toString().equals("")) {
                    //No pasa nada
                }
                //Casuistica 2 arriba con cuenta anterior, abajo nada
                else if (actual.getText().toString().equals("")) {

                }
                //Casuistica 3 arriba vacio
                else if (anterior.getText().toString().equals("")) {

                }
                //Casuistica 4 ambos con numero
                else {
                    actualDouble = Double.parseDouble(actual.getText().toString());
                    anteriorDouble = cuentacargada();
                    anterior.setText(Double.toString(anteriorDouble));
                    comprobarPunto0up();
                    actual.setText(anterior.getText().toString());
                    anterior.setText("");
                    operacionAnterior="";
                    actualDouble = anteriorDouble;
                    anteriorDouble=0.0;
                }
            }

        });
        punto.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (!actual.getText().toString().contains(String.valueOf('.'))) {
                    // Casuistica 1 arriba vacio y abajo vacio
                    if (anterior.getText().toString().equals("") && actual.getText().toString().equals("")) {
                        actual.setText(actual.getText() + "0.");
                    }
                    //Casuistica 2 arriba con cuenta anterior, abajo nada
                    else if (actual.getText().toString().equals("")) {
                        actual.setText(actual.getText() + "0.");
                    }
                    //Casuistica 3 arriba vacio
                    else if (anterior.getText().toString().equals("")) {
                        actual.setText(actual.getText() + ".");
                    }
                    //Casuistica 4 ambos con numero
                    else {
                        actual.setText(actual.getText() + ".");
                    }
                }
            }

        });
    };

    /**
     * @Brief modulo para que sea llamado en los cambios en el TextView de arriba para evitar tener un .0 (Ejemplo 5.0 -> 5)
     *
     */

    public void comprobarPunto0up () {
        if (anterior.length() > 2) {
            if (anterior.getText().toString().substring(anterior.length() - 2, anterior.length()).equals(".0")) {
                anterior.setText(anterior.getText().toString().substring(0, anterior.length() - 2));
            }
        }
    }

    /**
     * @Brief modulo para que sea llamado en los cambios en el TextView de abajo para evitar tener un .0 (Ejemplo 5.0 -> 5)
     *
     */
    public void comprobarPunto0 () {
        if (actual.length() > 2) {
            if (actual.getText().toString().substring(actual.length() - 2, actual.length()).equals(".0")) {
                actual.setText(actual.getText().toString().substring(0, actual.length() - 2));
            }
        }
    }

    /**
     * @Brief modulo para calcular una opracion previamente formulada
     *
     */
    public double cuentacargada (){
        double num=0.0;

        if (operacionAnterior.equals("+")) {
            num=anteriorDouble+actualDouble;
        }
        else if (operacionAnterior.equals("-")) {
            num=anteriorDouble-actualDouble;
        }
        else if (operacionAnterior.equals("X")) {
            num=anteriorDouble*actualDouble;
        }
        else if (operacionAnterior.equals("÷")) {
            num=anteriorDouble/actualDouble;
        }

        return num;
    }
}
extends Control

var COLLECTION_ID = "perfil_usuario"

var partidasJugadas = 0
var partidasGanadasBlancas = 0
var partidasGanadasNegras = 0
var user_name = ""

#Variables de estado de la jugada
var turnoBlanco = true
var jugadaIniciada = false
var lastBtPresed

#Vaiables de skin de fichas
var skinTorreBlanco
var skinTorreNegro
var skinCaballoBlanco
var skinCaballoNegro
var skinAlfilBlanco
var skinAlfilNegro
var skinReyBlanco
var skinReyNegro
var skinReinaBlanco
var skinReinaNegro
var skinPeonBlanco
var skinPeonNegro


# Called when the node enters the scene tree for the first time.
func _ready():
	loadData()
	#auxiliares
	var i=8
	var j=0
	var casilla="";
	
	#Variables de sking de casilla
	var casillaBlanca="Casilla2.png";
	var casillaNegra="Casilla1.png";
	
	#variables de skin de movimiento
	var newSkinThis="this1.png";
	var newSkinAttack="attack1.png";
	var newSkinMov="move1.png";
	
	#inicializamos variables de skin de ficha
	#TODO obtener las skins que tiene seleccionadas el usuario 
	skinTorreBlanco ="torre1.png"
	skinTorreNegro ="torre2.png"
	skinCaballoBlanco ="caballo1.png"
	skinCaballoNegro ="caballo2.png"
	skinAlfilBlanco ="alfil1.png"
	skinAlfilNegro ="alfil2.png"
	skinReyBlanco ="rey1.png"
	skinReyNegro ="rey2.png"
	skinReinaBlanco ="reina1.png"
	skinReinaNegro ="reina2.png"
	skinPeonBlanco ="peon1.png"
	skinPeonNegro ="peon2.png"
	
	#Recorremos el tablero en busca de filas
	for child in $Background/Tablero.get_children():
		if child is HBoxContainer: 
			#Recorremos las filas en busca de Casillas
			for child2 in child.get_children():
				if child2 is Casilla:
					j+=1
					#Designamos la skin de la casilla
					if (j%2!=0 && i%2==0):
						casilla = casillaBlanca;
					elif (j%2==0 && i%2!=0):
						casilla = casillaBlanca;
					else:
						casilla = casillaNegra;
						
					#Inicializamos la casilla
					child2.init(i, j, casilla, newSkinThis, newSkinAttack, newSkinMov)
		i-=1
		j=0
	#inicializamos las fichas
	iniciarFichas()


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
	
#cuando se pulsa un boton
func touchBT(btPresed):
	#comprobar si ya me estoy moviendo
	if (jugadaIniciada):
		tryMove(lastBtPresed, btPresed)
	else:
		if ((btPresed.get_parent().get_children().size()-1)<2):
			#print("SIN-INICIAR-JUGADA" + "-->" + "PULSANDOVACIO")
			pass
		elif (turnoBlanco==btPresed.get_parent().get_child(2).equipoBlanco):
			#print("SIN-INICIAR-JUGADA" + "-->" + "PULSANDOMIEQUIPO")
			pintarMovimientos(btPresed)
			lastBtPresed = btPresed
			jugadaIniciada = true
		else:
			#print("SIN-INICIAR-JUGADA" + "-->" + "NO_PULSANDOMIEQUIPO")
			pass

func tryMove (lastBtPresed, btPresed):
	var moviendo
	var matado
	
	if(btPresed.get_parent().movible==true):
		moviendo = lastBtPresed.get_parent().get_child(2)
		lastBtPresed.get_parent().remove_child(moviendo)
		btPresed.get_parent().add_child(moviendo)
		moviendo.posX = btPresed.get_parent().posX
		moviendo.posY = btPresed.get_parent().posY
		jugadaIniciada = false
		turnoBlanco = !turnoBlanco
		limpiarTablero()
		if(turnoBlanco && btPresed.get_parent().get_child(2).tipoFicha=="peon" && btPresed.get_parent().posY==1):
				btPresed.get_parent().get_child(2).init("reina", skinReinaNegro, btPresed.get_parent().posY, btPresed.get_parent().posX, false)
				#PreguntarFicha
		elif((!turnoBlanco) && btPresed.get_parent().get_child(2).tipoFicha=="peon" && btPresed.get_parent().posY==8):
				btPresed.get_parent().get_child(2).init("reina", skinReinaBlanco, btPresed.get_parent().posY, btPresed.get_parent().posX, true)
				#PreguntarFicha

	elif(btPresed.get_parent().matable==true):
		matado = btPresed.get_parent().get_child(2)
		btPresed.get_parent().remove_child(matado)
		
		moviendo = lastBtPresed.get_parent().get_child(2)
		lastBtPresed.get_parent().remove_child(moviendo)
		
		btPresed.get_parent().add_child(moviendo)
		#TODO deadZone.get_parent().add_child(matado)
		
		moviendo.posX = btPresed.get_parent().posX
		moviendo.posY = btPresed.get_parent().posY
		
		jugadaIniciada = false
		turnoBlanco = !turnoBlanco
		limpiarTablero()
		if(matado.tipoFicha=="rey"):
			#TODO indicar victoria
			if (turnoBlanco):
				partidasGanadasNegras+=1
			else:
				partidasGanadasBlancas+=1
			cerrar()
		elif(turnoBlanco && btPresed.get_parent().get_child(2).tipoFicha=="peon" && btPresed.get_parent().posY==1):
				btPresed.get_parent().get_child(2).init("reina", skinReinaNegro, btPresed.get_parent().posY, btPresed.get_parent().posX, false)
				#PreguntarFicha
		elif((!turnoBlanco) && btPresed.get_parent().get_child(2).tipoFicha=="peon" && btPresed.get_parent().posY==8):
				btPresed.get_parent().get_child(2).init("reina", skinReinaBlanco, btPresed.get_parent().posY, btPresed.get_parent().posX, true)
				#PreguntarFicha
	
	else:
		jugadaIniciada = false
		limpiarTablero()

	
	
func pintarMovimientos (btPresed):
	
	var tipo =  btPresed.get_parent().get_child(2).tipoFicha
	
	btPresed.get_parent().setPosition()
	
	if (tipo=="peon"):
		pintarPeon(btPresed)
	elif (tipo=="rey"):
		pintarRey(btPresed)
	elif (tipo=="reina"):
		pintarRectas(btPresed)
		pintarDiagonal(btPresed)
		pass
	elif (tipo=="torre"):
		pintarRectas(btPresed)
		pass
	elif (tipo=="caballo"):
		pintarCaballo(btPresed)
	elif (tipo=="alfil"):
		pintarDiagonal(btPresed)
		pass
		
	
					
func pintarPeon (btPresed):
	var numIni = btPresed.get_parent().get_child(2).posY
	var letraIni = btPresed.get_parent().get_child(2).posX
	var iniPeon = 0
	var direccionPeon = 0
	var filaIntermedia
	
	if (turnoBlanco):
		iniPeon=2
		direccionPeon=1
		filaIntermedia = $Background/Tablero/Fila3
	else: 
		iniPeon=7
		direccionPeon=-1
		filaIntermedia = $Background/Tablero/Fila6
	

	for fila in $Background/Tablero.get_children():
		if fila is HBoxContainer: 
			
			#Recorremos las filas en busca de Casillas
			for casillaEncontrada in fila.get_children():
				if casillaEncontrada is Casilla:

					#Condicion para matar
					if (((casillaEncontrada.posX==letraIni+1 || 
					casillaEncontrada.posX==letraIni-1)&&
					casillaEncontrada.posY==numIni+direccionPeon)&&
					casillaEncontrada.get_children().size()>2 &&
					casillaEncontrada.get_child(2).equipoBlanco!=turnoBlanco):
						casillaEncontrada.setPosibleAtaque()
					#Condicion para movimiento inicial
					if (numIni==iniPeon && 
					casillaEncontrada.posX == letraIni && 
					casillaEncontrada.posY == numIni+(2*direccionPeon) &&
					casillaEncontrada.get_children().size()<=2 &&
					filaIntermedia.get_child(casillaEncontrada.posX-1).get_children().size()<=2): 
						casillaEncontrada.setPosibleMov()
					#Condicion para mover una hacia delante
					if (casillaEncontrada.posX == letraIni && 
					casillaEncontrada.posY == numIni+(direccionPeon) &&
					casillaEncontrada.get_children().size()<=2):
						casillaEncontrada.setPosibleMov()

func pintarCaballo(btPresed):
	var difY
	var difX
	for fila in $Background/Tablero.get_children():
		if fila is HBoxContainer: 
			
			#Recorremos las filas en busca de Casillas
			for casillaEncontrada in fila.get_children():
				if casillaEncontrada is Casilla:
					difX = abs(casillaEncontrada.posX - btPresed.get_parent().posX)
					difY = abs(casillaEncontrada.posY - btPresed.get_parent().posY)

					if(
					((difX == 2)&&(difY == 1))||
					((difX == 1)&&(difY == 2))
					):
						if (casillaEncontrada.get_children().size()<=2):
							casillaEncontrada.setPosibleMov()
						else:
							if (casillaEncontrada.get_child(2).equipoBlanco!=turnoBlanco):
								casillaEncontrada.setPosibleAtaque()
								
func pintarRey(btPresed):
	var difY
	var difX
	for fila in $Background/Tablero.get_children():
		if fila is HBoxContainer: 
			
			#Recorremos las filas en busca de Casillas
			for casillaEncontrada in fila.get_children():
				if casillaEncontrada is Casilla:
					difX = abs(casillaEncontrada.posX - btPresed.get_parent().posX)
					difY = abs(casillaEncontrada.posY - btPresed.get_parent().posY)

					if(
					((difX == 1)&&(difY == 1))||
					((difX == 1)&&(difY == 1))||
					((difX == 0)&&(difY == 1))||
					((difX == 1)&&(difY == 0))
					):
						if (casillaEncontrada.get_children().size()<=2):
							casillaEncontrada.setPosibleMov()
						else:
							if (casillaEncontrada.get_child(2).equipoBlanco!=turnoBlanco):
								casillaEncontrada.setPosibleAtaque()
								


func pintarRectas(btPresed):
	var difY
	var difX
	var fichaInterponiendose###
	
	for fila in $Background/Tablero.get_children():
		if fila is HBoxContainer: 
			#Recorremos las filas en busca de Casillas
			for casillaEncontrada in fila.get_children():
				if casillaEncontrada is Casilla:
					difX = (casillaEncontrada.posX - btPresed.get_parent().posX)
					difY = (casillaEncontrada.posY - btPresed.get_parent().posY)
					if(
					((difX == 0)&&(difY != 0))||
					((difX != 0)&&(difY == 0))
					):
						fichaInterponiendose=false
						if (difX == 0):
							if (difY>0):
								#Hacia arriba
								for i in range(1, difY):
									if (($Background/Tablero.get_child(8-(casillaEncontrada.posY-i))).get_child(btPresed.get_parent().posX-1).get_children().size()>2):
										fichaInterponiendose=true
										#print("FICHA EN MEDIO")
							else:
								#Hacia abajo
								for i in range(1, abs(difY)):
									if (($Background/Tablero.get_child(8-(casillaEncontrada.posY+i))).get_child(btPresed.get_parent().posX-1).get_children().size()>2):
										fichaInterponiendose=true
										#print("FICHA EN MEDIO")
						else:
							if (difX>0):
								#Hacia derecha
								for i in range(1, abs(difX)):
									if (($Background/Tablero.get_child(8-(btPresed.get_parent().posY))).get_child(casillaEncontrada.posX-i-1).get_children().size()>2):
										fichaInterponiendose=true
										#print("FICHA EN MEDIO")
							else:
								#Hacia izquierda
								for i in range(1, abs(difX)):
									if (($Background/Tablero.get_child(8-(btPresed.get_parent().posY))).get_child(casillaEncontrada.posX+i-1).get_children().size()>2):
										fichaInterponiendose=true
										#print("FICHA EN MEDIO")
						if(fichaInterponiendose):
							pass
						elif (casillaEncontrada.get_children().size()<=2):
							casillaEncontrada.setPosibleMov()
						else:
							if (casillaEncontrada.get_child(2).equipoBlanco!=turnoBlanco):
								casillaEncontrada.setPosibleAtaque()
								


func pintarDiagonal(btPresed):
	var difY
	var difX
	var fichaInterponiendose###
	
	for fila in $Background/Tablero.get_children():
		if fila is HBoxContainer: 
			#Recorremos las filas en busca de Casillas
			for casillaEncontrada in fila.get_children():
				if casillaEncontrada is Casilla:
					difX = (casillaEncontrada.posX - btPresed.get_parent().posX)
					difY = (casillaEncontrada.posY - btPresed.get_parent().posY)
					if(
					(abs(difX) == abs(difY))
					):
						fichaInterponiendose=false

						if (difY>0 && difX>0):
							#Hacia arriba derecha
							for i in range(1, difY):
								if (($Background/Tablero.get_child(8-(casillaEncontrada.posY-i))).get_child(casillaEncontrada.posX-i-1).get_children().size()>2):
									fichaInterponiendose=true
						elif (difY>0 && difX<0):
							#Hacia arriba izquierda
							for i in range(1, difY):
								if (($Background/Tablero.get_child(8-(casillaEncontrada.posY-i))).get_child(casillaEncontrada.posX+i-1).get_children().size()>2):
									fichaInterponiendose=true
						elif (difY<0 && difX>0):
							#Hacia abajo derecha
							for i in range(1, abs(difY)):
								#ARREGLAR
								if (($Background/Tablero.get_child(8-(casillaEncontrada.posY+i))).get_child(casillaEncontrada.posX-i-1).get_children().size()>2):
									fichaInterponiendose=true
						elif (difY<0 && difX<0):
							#Hacia abajo izquierda
							for i in range(1, abs(difY)):
								if (($Background/Tablero.get_child(8-(casillaEncontrada.posY+i))).get_child(casillaEncontrada.posX+i-1).get_children().size()>2):
									fichaInterponiendose=true
							
							
						if(fichaInterponiendose):
							pass
						elif (casillaEncontrada.get_children().size()<=2):
							casillaEncontrada.setPosibleMov()
						else:
							if (casillaEncontrada.get_child(2).equipoBlanco!=turnoBlanco):
								casillaEncontrada.setPosibleAtaque()
								


func limpiarTablero():
	for fila in $Background/Tablero.get_children():
		if fila is HBoxContainer: 
			#Recorremos las filas en busca de Casillas
			for casillaEncontrada in fila.get_children():
				if casillaEncontrada is Casilla:
					casillaEncontrada.clearStatus()

func cerrar(): 
	partidasJugadas+=1
	saveData()
	get_tree().change_scene_to_file("res://Scenes/Menu.tscn")

func iniciarFichas ():
	# EquipoNegro
	$Background/Tablero/Fila8/Casilla8A/Ficha8A.init("torre", skinTorreNegro, 8, 1, false)
	$Background/Tablero/Fila8/Casilla8B/Ficha8B.init("caballo", skinCaballoNegro, 8, 2, false)
	$Background/Tablero/Fila8/Casilla8C/Ficha8C.init("alfil", skinAlfilNegro, 8, 3, false)
	$Background/Tablero/Fila8/Casilla8D/Ficha8D.init("reina", skinReinaNegro, 8, 4, false)
	$Background/Tablero/Fila8/Casilla8E/Ficha8E.init("rey", skinReyNegro, 8, 5, false)
	$Background/Tablero/Fila8/Casilla8F/Ficha8F.init("alfil", skinAlfilNegro, 8, 6, false)
	$Background/Tablero/Fila8/Casilla8G/Ficha8G.init("caballo", skinCaballoNegro, 8, 7, false)
	$Background/Tablero/Fila8/Casilla8H/Ficha8H.init("torre", skinTorreNegro, 8, 8, false)
	$Background/Tablero/Fila7/Casilla7A/Ficha7A.init("peon", skinPeonNegro, 7, 1, false)
	$Background/Tablero/Fila7/Casilla7B/Ficha7B.init("peon", skinPeonNegro, 7, 2, false)
	$Background/Tablero/Fila7/Casilla7C/Ficha7C.init("peon", skinPeonNegro, 7, 3, false)
	$Background/Tablero/Fila7/Casilla7D/Ficha7D.init("peon", skinPeonNegro, 7, 4, false)
	$Background/Tablero/Fila7/Casilla7E/Ficha7E.init("peon", skinPeonNegro, 7, 5, false)
	$Background/Tablero/Fila7/Casilla7F/Ficha7F.init("peon", skinPeonNegro, 7, 6, false)
	$Background/Tablero/Fila7/Casilla7G/Ficha7G.init("peon", skinPeonNegro, 7, 7, false)
	$Background/Tablero/Fila7/Casilla7H/Ficha7H.init("peon", skinPeonNegro, 7, 8, false)
# EquipoBlanco
	$Background/Tablero/Fila1/Casilla1A/Ficha1A.init("torre", skinTorreBlanco, 1, 1, true)
	$Background/Tablero/Fila1/Casilla1B/Ficha1B.init("caballo", skinCaballoBlanco, 1, 2, true)
	$Background/Tablero/Fila1/Casilla1C/Ficha1C.init("alfil", skinAlfilBlanco, 1, 3, true)
	$Background/Tablero/Fila1/Casilla1D/Ficha1D.init("reina", skinReinaBlanco, 1, 4, true)
	$Background/Tablero/Fila1/Casilla1E/Ficha1E.init("rey", skinReyBlanco, 1, 5, true)
	$Background/Tablero/Fila1/Casilla1F/Ficha1F.init("alfil", skinAlfilBlanco, 1, 6, true)
	$Background/Tablero/Fila1/Casilla1G/Ficha1G.init("caballo", skinCaballoBlanco, 1, 7, true)
	$Background/Tablero/Fila1/Casilla1H/Ficha1H.init("torre", skinTorreBlanco, 1, 8, true)
	$Background/Tablero/Fila2/Casilla2A/Ficha2A.init("peon", skinPeonBlanco, 2, 1, true)
	$Background/Tablero/Fila2/Casilla2B/Ficha2B.init("peon", skinPeonBlanco, 2, 2, true)
	$Background/Tablero/Fila2/Casilla2C/Ficha2C.init("peon", skinPeonBlanco, 2, 3, true)
	$Background/Tablero/Fila2/Casilla2D/Ficha2D.init("peon", skinPeonBlanco, 2, 4, true)
	$Background/Tablero/Fila2/Casilla2E/Ficha2E.init("peon", skinPeonBlanco, 2, 5, true)
	$Background/Tablero/Fila2/Casilla2F/Ficha2F.init("peon", skinPeonBlanco, 2, 6, true)
	$Background/Tablero/Fila2/Casilla2G/Ficha2G.init("peon", skinPeonBlanco, 2, 7, true)
	$Background/Tablero/Fila2/Casilla2H/Ficha2H.init("peon", skinPeonBlanco, 2, 8, true)



######     Evetos de los botones     #####
func _on_button_casilla_8a_pressed():
	touchBT($Background/Tablero/Fila8/Casilla8A/ButtonCasilla8A)
func _on_button_casilla_8b_pressed():
	touchBT($Background/Tablero/Fila8/Casilla8B/ButtonCasilla8B)
func _on_button_casilla_8c_pressed():
	touchBT($Background/Tablero/Fila8/Casilla8C/ButtonCasilla8C)
func _on_button_casilla_8d_pressed():
	touchBT($Background/Tablero/Fila8/Casilla8D/ButtonCasilla8D)
func _on_button_casilla_8e_pressed():
	touchBT($Background/Tablero/Fila8/Casilla8E/ButtonCasilla8E)
func _on_button_casilla_8f_pressed():
	touchBT($Background/Tablero/Fila8/Casilla8F/ButtonCasilla8F)
func _on_button_casilla_8g_pressed():
	touchBT($Background/Tablero/Fila8/Casilla8G/ButtonCasilla8G)
func _on_button_casilla_8h_pressed():
	touchBT($Background/Tablero/Fila8/Casilla8H/ButtonCasilla8H)
func _on_button_casilla_7a_pressed():
	touchBT($Background/Tablero/Fila7/Casilla7A/ButtonCasilla7A)
func _on_button_casilla_7b_pressed():
	touchBT($Background/Tablero/Fila7/Casilla7B/ButtonCasilla7B)
func _on_button_casilla_7c_pressed():
	touchBT($Background/Tablero/Fila7/Casilla7C/ButtonCasilla7C)
func _on_button_casilla_7d_pressed():
	touchBT($Background/Tablero/Fila7/Casilla7D/ButtonCasilla7D)
func _on_button_casilla_7e_pressed():
	touchBT($Background/Tablero/Fila7/Casilla7E/ButtonCasilla7E)
func _on_button_casilla_7f_pressed():
	touchBT($Background/Tablero/Fila7/Casilla7F/ButtonCasilla7F)
func _on_button_casilla_7g_pressed():
	touchBT($Background/Tablero/Fila7/Casilla7G/ButtonCasilla7G)
func _on_button_casilla_7h_pressed():
	touchBT($Background/Tablero/Fila7/Casilla7H/ButtonCasilla7H)
func _on_button_casilla_6a_pressed():
	touchBT($Background/Tablero/Fila6/Casilla6A/ButtonCasilla6A)
func _on_button_casilla_6b_pressed():
	touchBT($Background/Tablero/Fila6/Casilla6B/ButtonCasilla6B)
func _on_button_casilla_6c_pressed():
	touchBT($Background/Tablero/Fila6/Casilla6C/ButtonCasilla6C)
func _on_button_casilla_6d_pressed():
	touchBT($Background/Tablero/Fila6/Casilla6D/ButtonCasilla6D)
func _on_button_casilla_6e_pressed():
	touchBT($Background/Tablero/Fila6/Casilla6E/ButtonCasilla6E)
func _on_button_casilla_6f_pressed():
	touchBT($Background/Tablero/Fila6/Casilla6F/ButtonCasilla6F)
func _on_button_casilla_6g_pressed():
	touchBT($Background/Tablero/Fila6/Casilla6G/ButtonCasilla6G)
func _on_button_casilla_6h_pressed():
	touchBT($Background/Tablero/Fila6/Casilla6H/ButtonCasilla6H)
func _on_button_casilla_5a_pressed():
	touchBT($Background/Tablero/Fila5/Casilla5A/ButtonCasilla5A)
func _on_button_casilla_5b_pressed():
	touchBT($Background/Tablero/Fila5/Casilla5B/ButtonCasilla5B)
func _on_button_casilla_5c_pressed():
	touchBT($Background/Tablero/Fila5/Casilla5C/ButtonCasilla5C)
func _on_button_casilla_5d_pressed():
	touchBT($Background/Tablero/Fila5/Casilla5D/ButtonCasilla5D)
func _on_button_casilla_5e_pressed():
	touchBT($Background/Tablero/Fila5/Casilla5E/ButtonCasilla5E)
func _on_button_casilla_5f_pressed():
	touchBT($Background/Tablero/Fila5/Casilla5F/ButtonCasilla5F)
func _on_button_casilla_5g_pressed():
	touchBT($Background/Tablero/Fila5/Casilla5G/ButtonCasilla5G)
func _on_button_casilla_5h_pressed():
	touchBT($Background/Tablero/Fila5/Casilla5H/ButtonCasilla5H)
func _on_button_casilla_4a_pressed():
	touchBT($Background/Tablero/Fila4/Casilla4A/ButtonCasilla4A)
func _on_button_casilla_4b_pressed():
	touchBT($Background/Tablero/Fila4/Casilla4B/ButtonCasilla4B)
func _on_button_casilla_4c_pressed():
	touchBT($Background/Tablero/Fila4/Casilla4C/ButtonCasilla4C)
func _on_button_casilla_4d_pressed():
	touchBT($Background/Tablero/Fila4/Casilla4D/ButtonCasilla4D)
func _on_button_casilla_4e_pressed():
	touchBT($Background/Tablero/Fila4/Casilla4E/ButtonCasilla4E)
func _on_button_casilla_4f_pressed():
	touchBT($Background/Tablero/Fila4/Casilla4F/ButtonCasilla4F)
func _on_button_casilla_4g_pressed():
	touchBT($Background/Tablero/Fila4/Casilla4G/ButtonCasilla4G)
func _on_button_casilla_4h_pressed():
	touchBT($Background/Tablero/Fila4/Casilla4H/ButtonCasilla4H)
func _on_button_casilla_3a_pressed():
	touchBT($Background/Tablero/Fila3/Casilla3A/ButtonCasilla3A)
func _on_button_casilla_3b_pressed():
	touchBT($Background/Tablero/Fila3/Casilla3B/ButtonCasilla3B)
func _on_button_casilla_3c_pressed():
	touchBT($Background/Tablero/Fila3/Casilla3C/ButtonCasilla3C)
func _on_button_casilla_3d_pressed():
	touchBT($Background/Tablero/Fila3/Casilla3D/ButtonCasilla3D)
func _on_button_casilla_3e_pressed():
	touchBT($Background/Tablero/Fila3/Casilla3E/ButtonCasilla3E)
func _on_button_casilla_3f_pressed():
	touchBT($Background/Tablero/Fila3/Casilla3F/ButtonCasilla3F)
func _on_button_casilla_3g_pressed():
	touchBT($Background/Tablero/Fila3/Casilla3G/ButtonCasilla3G)
func _on_button_casilla_3h_pressed():
	touchBT($Background/Tablero/Fila3/Casilla3H/ButtonCasilla3H)
func _on_button_casilla_2a_pressed():
	touchBT($Background/Tablero/Fila2/Casilla2A/ButtonCasilla2A)
func _on_button_casilla_2b_pressed():
	touchBT($Background/Tablero/Fila2/Casilla2B/ButtonCasilla2B)
func _on_button_casilla_2c_pressed():
	touchBT($Background/Tablero/Fila2/Casilla2C/ButtonCasilla2C)
func _on_button_casilla_2d_pressed():
	touchBT($Background/Tablero/Fila2/Casilla2D/ButtonCasilla2D)
func _on_button_casilla_2e_pressed():
	touchBT($Background/Tablero/Fila2/Casilla2E/ButtonCasilla2E)
func _on_button_casilla_2f_pressed():
	touchBT($Background/Tablero/Fila2/Casilla2F/ButtonCasilla2F)
func _on_button_casilla_2g_pressed():
	touchBT($Background/Tablero/Fila2/Casilla2G/ButtonCasilla2G)
func _on_button_casilla_2h_pressed():
	touchBT($Background/Tablero/Fila2/Casilla2H/ButtonCasilla2H)
func _on_button_casilla_1a_pressed():
	touchBT($Background/Tablero/Fila1/Casilla1A/ButtonCasilla1A)
func _on_button_casilla_1b_pressed():
	touchBT($Background/Tablero/Fila1/Casilla1B/ButtonCasilla1B)
func _on_button_casilla_1c_pressed():
	touchBT($Background/Tablero/Fila1/Casilla1C/ButtonCasilla1C)
func _on_button_casilla_1d_pressed():
	touchBT($Background/Tablero/Fila1/Casilla1D/ButtonCasilla1D)
func _on_button_casilla_1e_pressed():
	touchBT($Background/Tablero/Fila1/Casilla1E/ButtonCasilla1E)
func _on_button_casilla_1f_pressed():
	touchBT($Background/Tablero/Fila1/Casilla1F/ButtonCasilla1F)
func _on_button_casilla_1g_pressed():
	touchBT($Background/Tablero/Fila1/Casilla1G/ButtonCasilla1G)
func _on_button_casilla_1h_pressed():
	touchBT($Background/Tablero/Fila1/Casilla1H/ButtonCasilla1H)


func _on_close_pressed():
	cerrar()

#Cargar los datos
func loadData():
	var auth = Firebase.Auth.auth
	
	if auth.localid:
		#obtenemos la coleccion
		var collection: FirestoreCollection = Firebase.Firestore.collection(COLLECTION_ID)
		#obtenemos nuestra "id"
		var task: FirestoreTask = collection.get_doc(auth.localid)
		var finished_task: FirestoreTask = await task.task_finished
		#Cuando terminemos de obtener la "id" creamos una variable con el documento
		var document = finished_task.document
		#Comprobamos que este bien el documento
		if document && document.doc_fields:
			#Si tiene nombre de usuario lo ponemos en el texto del boton
			if document.doc_fields.user_name:
				user_name = document.doc_fields.user_name
			if document.doc_fields.partidasJugadas:
				partidasJugadas = document.doc_fields.partidasJugadas
			if document.doc_fields.partidasGanadasBlancas:
				partidasGanadasBlancas = document.doc_fields.partidasGanadasBlancas
			if document.doc_fields.partidasGanadasNegras:
				partidasGanadasNegras = document.doc_fields.partidasGanadasNegras

		else:
			print(finished_task.error)
			
#Guardar los cambios
func saveData():
	var auth = Firebase.Auth.auth
	if auth.localid:
		# Obtenemos la coleccion
		var collection: FirestoreCollection = Firebase.Firestore.collection(COLLECTION_ID)


		# Creamos la variable con los datos
		
		var data: Dictionary = {
			"user_name": user_name,
			"partidasJugadas": partidasJugadas,
			"partidasGanadasBlancas": partidasGanadasBlancas,
			"partidasGanadasNegras": partidasGanadasNegras
		}
		# Actualizamos la base de datos
		var task: FirestoreTask = collection.update(auth.localid, data)

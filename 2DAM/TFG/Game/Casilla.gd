extends Node2D
class_name Casilla

@onready var ID_CASILLA = ""
@onready var skinFicha = ""

var posX = 0;
var posY = 0;

var movible = false
var matable = false

func init(newposY, newposX, newskinFicha, newSkinThis, newSkinAttack, newSkinMov):
	ID_CASILLA = ""+str(newposX)+letra(newposY);
	skinFicha = newskinFicha
	var ruta = "res://Sprites/" + skinFicha
	$Fondo.texture=ResourceLoader.load(ruta)
	ruta = "res://Sprites/" + newSkinThis
	$Fondo/posicionIni.texture=ResourceLoader.load(ruta)
	ruta = "res://Sprites/" + newSkinMov
	$Fondo/posibleMov.texture=ResourceLoader.load(ruta)
	ruta = "res://Sprites/" + newSkinAttack
	$Fondo/posibleAttack.texture=ResourceLoader.load(ruta)
	
	posX = newposX
	posY = newposY
	
# Called when the node enters the scene tree for the first time.
func _ready():
	pass



# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass

func clearStatus ():
	$Fondo/posicionIni.visible = false
	$Fondo/posibleMov.visible = false
	$Fondo/posibleAttack.visible = false
	matable = false
	movible = false

func setPosibleAtaque():
	$Fondo/posibleAttack.visible=true
	matable = true

func setPosibleMov():
	$Fondo/posibleMov.visible=true
	movible = true

func setPosition():
	$Fondo/posicionIni.visible=true


#Funcion para obtener la letra de la casilla con el numero de esta en el eje x
func letra (num):
	var letra = ""
	if (num==1):
		letra="A"
	elif (num==2):
		letra="B"
	elif (num==3):
		letra="C"
	elif (num==4):
		letra="D"
	elif (num==5):
		letra="E"
	elif (num==6):
		letra="F"
	elif (num==7):
		letra="G"
	elif (num==8):
		letra="H"
	return letra

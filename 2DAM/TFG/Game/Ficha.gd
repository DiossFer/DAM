extends Node2D
class_name Ficha

@onready var tipoFicha = ""
@onready var skinFicha = ""

var posX = 0
var posY = 0

@onready var equipoBlanco


# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass


func init(newtipoFicha, newskinFicha, newPosY, newPosX, newEquipoBlanco):
	tipoFicha = newtipoFicha
	skinFicha = newskinFicha
	var ruta = "res://Sprites/" + skinFicha
	$skinFicha.texture=ResourceLoader.load(ruta)
	posX = newPosX
	posY = newPosY
	equipoBlanco=newEquipoBlanco



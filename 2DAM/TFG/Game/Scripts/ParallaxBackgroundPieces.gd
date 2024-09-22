extends ParallaxBackground


var DIR = Vector2 (1, 0)
var speed = 120

# Funcion de actualizacion
func _physics_process(delta):
	# Movemos el fondo
	scroll_base_offset += DIR * (-speed)  * delta

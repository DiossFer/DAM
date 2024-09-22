extends ParallaxBackground


var DIR = Vector2 (1, 0)
@onready var speed = 100

# Funcion de actualizacion
func _physics_process(delta):
	# Movemos el fondo
	scroll_base_offset += DIR * (-speed)  * delta

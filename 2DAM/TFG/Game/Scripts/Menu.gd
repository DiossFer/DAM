extends Control

var COLLECTION_ID = "perfil_usuario"

# Funcion llamada al inicio
func _ready():
	$ParallaxBackground.speed = 0
	loadData()

# Funcion de actualizacion
func _process(delta):
	pass

# Actual boton de cerrar sesion
func _on_cerrar_pressed():
	Firebase.Auth.logout()
	get_tree().change_scene_to_file("res://Scenes/Autentication.tscn")


# Boton para ir a la pantalla del perfil
func _on_perfil_pressed():
	get_tree().change_scene_to_file("res://Scenes/Perfil.tscn")

func _on_play_pressed():
	get_tree().change_scene_to_file("res://Scenes/game.tscn")

#Cargar los datos que mostramos
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
				$VBoxContainer/HBoxContainer/VBoxContainer/Perfil.text = document.doc_fields.user_name
				
		else:
			print(finished_task.error)

func _on_close_pressed():
	get_tree().quit()

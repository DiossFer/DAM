extends Control

var COLLECTION_ID = "perfil_usuario"

var partidasJugadas = 0
var partidasGanadasBlancas = 0
var partidasGanadasNegras = 0

# Funcion llamada al inicio
func _ready():
	loadData()
	$ParallaxBackground.speed = 0


# Funcion de actualizacion
func _process(delta):
	pass

# Guardamos los cambios
func _on_save_pressed():
	saveData()
	$VBoxContainer/VBoxContainer/Save.visible  = false
	$VBoxContainer/VBoxContainer/UserNameEdit.editable = false

# Editamos
func _on_edit_pressed():
	#$VBoxContainer/VBoxContainer/Save.visibility = Visibility.VISIBLE
	$VBoxContainer/VBoxContainer/Save.visible  = true
	$VBoxContainer/VBoxContainer/UserNameEdit.editable = true

# Volvemos al menu
func _on_exit_pressed():
	get_tree().change_scene_to_file("res://Scenes/Menu.tscn")

#Guardar los cambios
func saveData():
	var auth = Firebase.Auth.auth
	if auth.localid:
		# Obtenemos la coleccion
		var collection: FirestoreCollection = Firebase.Firestore.collection(COLLECTION_ID)
		# Preparamos los datos que vamos  a guardar
		var user_name = $VBoxContainer/VBoxContainer/UserNameEdit.text
		# Creamos la variable con los datos
		
		var data: Dictionary = {
			"user_name": user_name,
			"partidasJugadas": partidasJugadas,
			"partidasGanadasBlancas": partidasGanadasBlancas,
			"partidasGanadasNegras": partidasGanadasNegras
		}
		# Actualizamos la base de datos
		var task: FirestoreTask = collection.update(auth.localid, data)

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
				$VBoxContainer/VBoxContainer/UserNameEdit.text = document.doc_fields.user_name
			if document.doc_fields.partidasJugadas:
				partidasJugadas = document.doc_fields.partidasJugadas
			if document.doc_fields.partidasGanadasBlancas:
				partidasGanadasBlancas = document.doc_fields.partidasGanadasBlancas
			if document.doc_fields.partidasGanadasNegras:
				partidasGanadasNegras = document.doc_fields.partidasGanadasNegras
			mostrarEstadisticas()
		else:
			print(finished_task.error)
			
			
func mostrarEstadisticas():
	$VBoxContainer/VBoxContainer2/partidasJugadas.text=str(partidasJugadas)
	$VBoxContainer/VBoxContainer3/partidasGanadasBlancas.text=str(partidasGanadasBlancas)
	$VBoxContainer/VBoxContainer4/partidasGanadasNegras.text=str(partidasGanadasNegras)
	

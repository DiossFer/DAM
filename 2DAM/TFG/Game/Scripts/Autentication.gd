extends Control


# Funcion llamada al inicio
func _ready():
	#Si haces login llamas a on_login_succeeded
	Firebase.Auth.login_succeeded.connect(on_login_succeeded)
	
	#Si te registras llamas a on_signup_succeeded
	Firebase.Auth.signup_succeeded.connect(on_signup_succeeded)
	
	#Si falla el login llamas a on_login_failed
	Firebase.Auth.login_failed.connect(on_login_failed)
	
	#Si haces login llamas a on_login_succeeded
	Firebase.Auth.signup_failed.connect(on_signup_failed)
	
	# En caso de que ya hallas accedido con anterioridad lo detectaremos del sistema
	if Firebase.Auth.check_auth_file():
		$VBoxContainer/StateLabel.text = "Accedido"
		get_tree().change_scene_to_file("res://Scenes/Menu.tscn")


# Funcion de actualizacion
func _process(delta):
	pass

# Funcion para hacer login 
func _on_login_button_pressed():
	var email = $VBoxContainer/EmailEdit.text
	var password = $VBoxContainer/PasswordEdit.text
	Firebase.Auth.login_with_email_and_password(email, password)
	$VBoxContainer/StateLabel.text = "Accediendo"

# Funcion para registrarse
func _on_signup_button_pressed():
	var email = $VBoxContainer/EmailEdit.text
	var password = $VBoxContainer/PasswordEdit.text
	Firebase.Auth.signup_with_email_and_password(email, password)
	$VBoxContainer/StateLabel.text = "Registrado"

# En caso de que se acceda de manera correcta
func on_login_succeeded(auth):
	print(auth)
	$VBoxContainer/StateLabel.text = "Accedido"
	Firebase.Auth.save_auth(auth)
	get_tree().change_scene_to_file("res://Scenes/Menu.tscn")

# En caso de que se halla registrado de manera correcta
func on_signup_succeeded(auth):
	print(auth)
	$VBoxContainer/StateLabel.text = "Registro completado"
	Firebase.Auth.save_auth(auth)
	get_tree().change_scene_to_file("res://Scenes/Menu.tscn")

# En caso de que no se halla hecho login de manera correcta
func on_login_failed(error_code, message):
	print(error_code)
	print(message)
	$VBoxContainer/StateLabel.text = "Acceso fallido: %s" % message

# En caso de que no se halla podido registrar de manera correcta
func on_signup_failed(error_code, message):
	print(error_code)
	print(message)
	$VBoxContainer/StateLabel.text = "Registro fallido: %s" % message


func _on_close_pressed():
	get_tree().quit()

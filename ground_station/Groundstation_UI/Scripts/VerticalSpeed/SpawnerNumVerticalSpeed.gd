extends Node2D

#Decide se é para spawnar novos números ou não


var contM1 = 9
var contN1 = 5
var array_nodes = [] #array onde vao ser guardados os nodes
var slots = 0
#var aux = 9
func _ready():
	#if (float(global.array2[9]) >= (int(InitialAlt.pinit) * 10 + 10 * (contM -3))):
	#	contM +=1
	#aux = contM
	pass

#global.array2[9]
func _process(_delta):
	#print(Debug.x)
	#aux = _on_Sprite_Leitura(delta)
	#print(aux)
	if (float(global.array2[10]) > ( 2 * (contM1 -3))): #global.array2[13]
		#print("criou")
		
		#criar()
		contM1 += 1
		#criarPos()
		#print("dps de criar")
		#contM += 1
		#print(contM)
	
	if (float(global.array2[10]) < (-2 * (contN1-3))): 
		contN1 +=1
	##	criar()
		
		
func criarPos():
	#array_nodes.append([]) #necessário
	var caixa3 = preload("res://Scenes/SpawnNumVerticalSpeed.tscn")
	var caixaC3 = caixa3.instance()
	add_child_below_node(get_tree().get_root().get_node("PFD"), caixaC3)

func criarNeg():
	#array_nodes.append([]) #necessário
	var caixa = preload("res://Scenes/SpawnNumVerticalSpeedNeg.tscn")
	var caixaC = caixa.instance()
	add_child_below_node(get_tree().get_root().get_node("PFD"), caixaC)
	
func _on_Sprite_Leitura(array2, pinit, init):
	#print(array2[10])
	#print(contM1)
	#print(5 * (contM1 -3))
	if (float(array2[10]) >= (2 * (contM1 -3))): #trocar valor inicial #array2[13]
		#print("aaaaaaa")
		
		criarPos() #array2[9]
		contM1 += 1
		#print("criou")
	
	if (float(array2[10]) <= (-2 * (contN1-3))): #trocar valor inicial
		criarNeg()
		contN1 +=1

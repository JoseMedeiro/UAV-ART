extends Polygon2D    
#Código para a movimentação dos polígonos novos
#este código é muito semelhante ao script Num, do altimetro, que está mais comentado
var aux1 #salva o ultimo valor do contM
var aux2 #salva o ultimo valor do contN


func _ready():
	aux1 = SpawnerNumVerticalSpeed.contM1
	aux2 = SpawnerNumVerticalSpeed.contN1
	position.x = 306.0 + 7
func _process(_delta): 
	position.y = -29 - 100 + 49.3597 * (aux2+3) + (49.3597/2.0 * float(global.array2[12])) +16


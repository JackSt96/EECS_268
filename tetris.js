tetrisGame = {};
tetrisGame.currentState = [];
tetrisGame.initialized = false;
tetrisGame.falling = false;
tetrisGame.dotLocation = 0;
tetrisGame.shapeType = -1;
tetrisGame.position;
tetrisGame.movement = 0;

tetrisGame.AddShape = function(shapeType, position, id){
	// Instead of adding the shape based on the type,position, and id,
	// this code is just adding a dot and moving it around. You will
	// need to add real tetris shapes instead.
	this.shapeType = shapeType;
	this.position = position;
	AddToConsole("Adding shape with type = {"+shapeType+"}, position = {"+position+"}, and id = {" + id + "}");
	switch(this.shapeType)
	{
		case 0:
			if(!this.initialized){this.Initialize();}
			this.dotLocation = position;
			this.falling = true;
			this.currentState[this.dotLocation] = 0;
			this.currentState[this.dotLocation+1] = 0;
			this.currentState[this.dotLocation+2] = 0;
			this.currentState[this.dotLocation+3] = 0;
			break;
		case 1:
			if(!this.initialized){this.Initialize();}
			this.dotLocation = position;
			this.falling = true;
			this.currentState[this.dotLocation] = 1;
			this.currentState[this.dotLocation+1] = 1;
			this.currentState[this.dotLocation+2] = 1;
			this.currentState[this.dotLocation+11] = 1;

			break;
		case 2:
			if(!this.initialized){this.Initialize();}
			this.dotLocation = position;
			this.falling = true;
			this.currentState[this.dotLocation] = 2;
			this.currentState[this.dotLocation+1] = 2;
			this.currentState[this.dotLocation+12] = 2;
			this.currentState[this.dotLocation+11] = 2;
			break;
		case 3:
			if(!this.initialized){this.Initialize();}
			this.dotLocation = position;
			this.falling = true;
			this.currentState[this.dotLocation+1] = 3;
			this.currentState[this.dotLocation+2] = 3;
			this.currentState[this.dotLocation+10] = 3;
			this.currentState[this.dotLocation+11] = 3;
			break;
		case 4:
			if(!this.initialized){this.Initialize();}
			this.dotLocation = position;
			this.falling = true;
			this.currentState[this.dotLocation] = 4;
			this.currentState[this.dotLocation+1] = 4;
			this.currentState[this.dotLocation+10] = 4;
			this.currentState[this.dotLocation+11] = 4;
			break;
		case 5:
			if(!this.initialized){this.Initialize();}
			this.dotLocation = position;
			this.falling = true;
			this.currentState[this.dotLocation] = 5;
			this.currentState[this.dotLocation+10] = 5;
			this.currentState[this.dotLocation+12] = 5;
			this.currentState[this.dotLocation+11] = 5;
			break;
		case 6:
			if(!this.initialized){this.Initialize();}
			this.dotLocation = position;
			this.falling = true;
			this.currentState[this.dotLocation] = 6;
			this.currentState[this.dotLocation+1] = 6;
			this.currentState[this.dotLocation+2] = 6;
			this.currentState[this.dotLocation+10] = 6;
			break;
	}
	
	/*
	if(!this.initialized){this.Initialize();}
	this.dotLocation = 0;
	this.falling = true;
	this.currentState[this.dotLocation] = 1;*/
}

tetrisGame.IncrementTime = function(){
	if(!this.initialized){this.Initialize();}
	if(this.falling == false)
		return;
	this.analyzeGame();
	switch(this.shapeType)
	{
		case 0:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 3 >= this.currentState.length){
				this.falling = false;
				return;
			}
			this.currentState[this.dotLocation] = -1;
			this.currentState[this.dotLocation+1] = -1;
			this.currentState[this.dotLocation+2] = -1;
			this.currentState[this.dotLocation+3] = -1;
			break;
		case 1:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 11 >= this.currentState.length){
				this.falling = false;
				return;
			}
			this.currentState[this.dotLocation] = -1;
			this.currentState[this.dotLocation+1] = -1;
			this.currentState[this.dotLocation+2] = -1;
			this.currentState[this.dotLocation+11] = -1;

			break;
		case 2:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 12 >= this.currentState.length){
				this.falling = false;
				return;
			}
			this.currentState[this.dotLocation] = -1;
			this.currentState[this.dotLocation+1] = -1;
			this.currentState[this.dotLocation+12] = -1;
			this.currentState[this.dotLocation+11] = -1;
			break;
		case 3:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 11 >= this.currentState.length){
				this.falling = false;
				return;
			}
			this.currentState[this.dotLocation+1] = -1;
			this.currentState[this.dotLocation+2] = -1;
			this.currentState[this.dotLocation+10] = -1;
			this.currentState[this.dotLocation+11] = -1;
			break;
		case 4:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 11 >= this.currentState.length){
				this.falling = false;
				return;
			}
			this.currentState[this.dotLocation] = -1;
			this.currentState[this.dotLocation+1] = -1;
			this.currentState[this.dotLocation+10] = -1;
			this.currentState[this.dotLocation+11] = -1;
			break;
		case 5:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 12 >= this.currentState.length){
				this.falling = false;
				return;
			}
			this.currentState[this.dotLocation] = -1;
			this.currentState[this.dotLocation+10] = -1;
			this.currentState[this.dotLocation+12] = -1;
			this.currentState[this.dotLocation+11] = -1;
			break;
		case 6:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 10 >= this.currentState.length){
				this.falling = false;
				return;
			}
			this.currentState[this.dotLocation] = -1;
			this.currentState[this.dotLocation+1] = -1;
			this.currentState[this.dotLocation+2] = -1;
			this.currentState[this.dotLocation+10] = -1;
			break;
	}
	// Set the current position of the dot to be empty
/*	this.currentState[this.dotLocation] = -1;
	if(this.dotLocation + 1 == this.currentState.length){
		this.falling = false;
		return;
	}*/
	
	// Move the dotLocation
	this.dotLocation = this.dotLocation + 10 + this.movement;
				if(this.dotLocation + 10 >= this.currentState.length){
				this.falling = false;
				return;
			}
	
	switch(this.shapeType)
	{
		case 0:
//			if(!this.initialized){this.Initialize();}

			this.falling = true;
			this.currentState[this.dotLocation] = 0;
			this.currentState[this.dotLocation+1] = 0;
			this.currentState[this.dotLocation+2] = 0;
			this.currentState[this.dotLocation+3] = 0;
			break;
		case 1:
//			if(!this.initialized){this.Initialize();}

			this.falling = true;
			this.currentState[this.dotLocation] = 1;
			this.currentState[this.dotLocation+1] = 1;
			this.currentState[this.dotLocation+2] = 1;
			this.currentState[this.dotLocation+11] = 1;

			break;
		case 2:
//			if(!this.initialized){this.Initialize();}

			this.falling = true;
			this.currentState[this.dotLocation] = 2;
			this.currentState[this.dotLocation+1] = 2;
			this.currentState[this.dotLocation+12] = 2;
			this.currentState[this.dotLocation+11] = 2;
			break;
		case 3:
//			if(!this.initialized){this.Initialize();}

			this.falling = true;
			this.currentState[this.dotLocation+1] = 3;
			this.currentState[this.dotLocation+2] = 3;
			this.currentState[this.dotLocation+10] = 3;
			this.currentState[this.dotLocation+11] = 3;
			break;
		case 4:
//			if(!this.initialized){this.Initialize();}

			this.falling = true;
			this.currentState[this.dotLocation] = 4;
			this.currentState[this.dotLocation+1] = 4;
			this.currentState[this.dotLocation+10] = 4;
			this.currentState[this.dotLocation+11] = 4;
			break;
		case 5:
//			if(!this.initialized){this.Initialize();}

			this.falling = true;
			this.currentState[this.dotLocation] = 5;
			this.currentState[this.dotLocation+10] = 5;
			this.currentState[this.dotLocation+12] = 5;
			this.currentState[this.dotLocation+11] = 5;
			break;
		case 6:
//			if(!this.initialized){this.Initialize();}

			this.falling = true;
			this.currentState[this.dotLocation] = 6;
			this.currentState[this.dotLocation+1] = 6;
			this.currentState[this.dotLocation+2] = 6;
			this.currentState[this.dotLocation+10] = 6;
			break;
	}
}

tetrisGame.GetCurrentState = function(){
	if(!this.initialized){this.Initialize();}
	return this.currentState;
}

tetrisGame.IsShapeFalling = function(){
	if(!this.initialized){this.Initialize();}
//	AddToConsole("currentState {"+this.currentState[this.dotLocation + 10]+"}");
	switch(this.shapeType)
	{
		case 0:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 3 >= this.currentState.length - 10 || this.dotLocation + 2 >= this.currentState.length - 10|| this.dotLocation + 1 >= this.currentState.length - 10|| this.dotLocation + 0 >= this.currentState.length - 10 || this.currentState[this.dotLocation + 13] != -1 || this.currentState[this.dotLocation + 12] != -1 || this.currentState[this.dotLocation + 11] != -1 || this.currentState[this.dotLocation + 10] != -1 ){
				this.falling = false;
				return;
			}
			break;
		case 1:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 11 >= this.currentState.length - 10|| this.dotLocation + 2 >= this.currentState.length - 10 || this.dotLocation + 1 >= this.currentState.length - 10|| this.dotLocation + 0 >= this.currentState.length - 10 || this.currentState[this.dotLocation + 12] != -1 || this.currentState[this.dotLocation + 21] != -1 || this.currentState[this.dotLocation + 10] != -1 ){
				this.falling = false;
				return;
			}
			break;
		case 2:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 11 >= this.currentState.length - 10|| this.dotLocation + 12 >= this.currentState.length - 10 || this.dotLocation + 1 >= this.currentState.length - 10|| this.dotLocation + 0 >= this.currentState.length - 10 || this.currentState[this.dotLocation + 10] != -1 || this.currentState[this.dotLocation + 22] != -1 || this.currentState[this.dotLocation + 21] != -1){
				this.falling = false;
				return;
			}
			break;
		case 3:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 11 >= this.currentState.length - 10|| this.dotLocation + 2 >= this.currentState.length - 10|| this.dotLocation + 1 >= this.currentState.length - 10 || this.dotLocation + 10 >= this.currentState.length - 10 || this.currentState[this.dotLocation + 21] != -1|| this.currentState[this.dotLocation + 12] != -1 || this.currentState[this.dotLocation + 20] != -1){
				this.falling = false;
				return;
			}
			break;
		case 4:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 11 >= this.currentState.length - 10|| this.dotLocation + 0 >= this.currentState.length - 10|| this.dotLocation + 1 >= this.currentState.length - 10|| this.dotLocation + 10 >= this.currentState.length - 10 || this.currentState[this.dotLocation + 21] != -1|| this.currentState[this.dotLocation + 20] != -1){
				this.falling = false;
				return;
			}
			break;
		case 5:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 11 >= this.currentState.length - 10 || this.dotLocation + 12 >= this.currentState.length - 10|| this.dotLocation + 0 >= this.currentState.length - 10|| this.dotLocation + 10 >= this.currentState.length - 10 || this.currentState[this.dotLocation + 20] != -1|| this.currentState[this.dotLocation + 21] != -1 || this.currentState[this.dotLocation + 22] != -1){
				this.falling = false;
				return;
			}
			break;
		case 6:
//			if(!this.initialized){this.Initialize();}
			if(this.dotLocation + 0 >= this.currentState.length - 10 || this.dotLocation + 2 >= this.currentState.length - 10|| this.dotLocation + 1 >= this.currentState.length - 10 || this.dotLocation + 10 >= this.currentState.length - 10 || this.currentState[this.dotLocation + 20] != -1|| this.currentState[this.dotLocation + 11] != -1 || this.currentState[this.dotLocation + 12] != -1){
				this.falling = false;
				return;
			}
			break;
	}
	
	return tetrisGame.falling;
}

tetrisGame.Initialize = function(){
	for(var i = 0; i < 10; i++){
		for(var j = 0; j < 20; j++){
			this.currentState.push(-1);
		}
	}
	this.initialized = true;
}


tetrisGame.analyzeGame = function(){
	counter = 0;
	this.movement = 0;
	switch(this.shapeType)
	{
		case 0:
			while(counter < this.currentState.length-1)
			{
				if(this.currentState[199-counter] == -1 && this.currentState[199-(counter+1)] == -1 && this.currentState[199-(counter+2)] == -1 && this.currentState[199-(counter+3)] == -1){ 
					if((counter%10) == this.position)
					{
						this.movement = 0;
						this.position = this.position + 0;
						return;
					}
					else if((counter%10) >= this.position)
					{
						this.position = this.position + -1;
						this.movement = -1;
						return;
					}
					else if((counter%10) <= this.position)
					{
						this.position = this.position + 1;
						this.movement = 1;
						return;
					}
					return;
				}
				if((counter%10) == 6)
				{
					counter += 4;
				}
				else
					counter++;
			}
			
			break;
		case 1:
			while(counter < this.currentState.length-1)
			{
				AddToConsole("printing counter " + counter);
				if(this.currentState[199-(counter+10)] == -1 && this.currentState[199-(counter+1)] == -1 && this.currentState[199-(counter+12)] == -1){ 
					if((counter%10) == this.position)
					{
						this.movement = 0;
						this.position = this.position + 0;
						return;
					}
					else if((counter%10) <= this.position)
					{
						this.movement = -1;
						this.position = this.position + -1;
						return;
					}
					else if((counter%10) >= this.position)
					{
						this.movement = 1;
						this.position = this.position + 1;
						return;
					}
					return;
				}
				if((counter%10) == 7)
				{
					counter += 3;
				}
				else
					counter++;
				
			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
	}
}

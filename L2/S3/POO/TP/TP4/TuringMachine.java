public class TuringMachine{
	
	private boolean tape[];
	private int index,state;
	
	TuringMachine(int n){
		this.tape = new boolean [n];
		this.state = 1;
		this.index = 0;
	}
	
	TuringMachine(){
		this(1000);
	}
	
	void write(){
		this.tape[index] = true;
	}
	
	void erase(){
		this.tape[index] = false;
	}
	
	boolean read(){
		return this.tape[index];
	}
	
	int getState(){
		return this.state;
	}
	
	int getIndex(){
		return this.index;
	}
	
	void setState(int n){
		this.state = n;
	}
	
	boolean goRight(){
		if(this.index<this.tape.length-1){
			this.index++;
			return true;
		}
		else return false;
	}
	
	boolean goLeft(){
			if(this.index>0) {
				this.index--;
				return true;
			}
			else return false;
	}
	
	void goTo(int n){
		if(n >= 0 && n < this.tape.length){
			while(this.goLeft()){}
			for(int i=0; i<n; i++) this.goRight();
		}
	}
	
	void process(Program p){
		this.state = 1;
		Instruction currentInstruction;
		while(this.goLeft()){}
		while (this.state != 0){
			currentInstruction = p.getInstruction(this.state , this.read());
			Ecran.afficherln("Instruction courrante : ");
			Ecran.afficherln(currentInstruction);
			System.out.println("Etat machine : "+this+"\n\n");
			this.execute(currentInstruction.getActions());
			this.setState(currentInstruction.getNextState());
		}
	}
	
	void execute(String actions){
		for(int i=0; i<actions.length(); i++){
			switch(actions.charAt(i)){
				case 'r' : this.goRight();break;
				case 'l' : this.goLeft();break;
				case 'w' : this.write();break;
				case 'e' : this.erase();break;
				case 'n' : {};break;
				default : {
					System.out.println("Erreur lors de l'execution de l'action "+actions.charAt(i));
					System.exit(1);
				}
			}
		}
	}
	
        public String toString() {
	    String sTape = "";
	    for (int i=0; i<tape.length; i++)
		if (i==index)
		    sTape += "["+(tape[i] ? "1" : "_")+"]";
		else
		    sTape += (tape[i] ? "1" : "_");
	    
	    return sTape;
	}
	
}

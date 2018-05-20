public class GoTuringMachine{
	static void config (TuringMachine m, boolean [] cfg){
		while(m.goLeft());
		int i=0;
		do{
			if(cfg[i]) m.write();
			else m.erase();
			i++;
		}while(m.goRight());
		System.out.println("Etat apres configuration :\n"+m);
	}
	
	static void additionProgram(Program p){
		p.add(1, false, "r", 1);
		p.add(1, true, "r", 2);
		p.add(2, true, "r", 2);
		p.add(2, false, "wr", 3);
		p.add(3, true, "r", 3);
		p.add(3, false, "le", 0);
	}
	
	static void eraseNextWordProgram(Program p){
		p.add(1, false, "r", 1);
		p.add(1, true, "r", 2);
		p.add(2, true, "r", 2);
		p.add(2, false, "r", 3);
		p.add(3, true, "er", 3);
		p.add(3, false, "n", 0);
	}
	
	static void arrondiProgram(Program p){
		p.add(1,false,"r",1);
		p.add(1,true,"r",2);
		p.add(2,true,"r",3);
		p.add(3,false,"r",0);
		p.add(3,true,"r",2);
		p.add(2,false,"wr",0);
	}
	
	public static void main(String[]args){
		TuringMachine m = new TuringMachine(14);
		Program prog = new Program("ADDITION" , 6);
		additionProgram(prog);
		Program prog2 = new Program("ERASE NEXT WORD",6);
		eraseNextWordProgram(prog2);
		Program prog3 = new Program("ARRONDIS MADAFAKA",6);
		arrondiProgram(prog3);
		boolean cfg[] = {false,false,true,true,true,false,true,true,true,true,true,false,false,false};
		boolean cfg2[] = {false,false,true,true,true,true,true,true,true,true,true,false,false,false};
		config(m,cfg);
		m.goTo(6);
		System.out.println("Fin de la configuration :\n"+m);
		Instruction i = new Instruction(1,true,"r",1);
		System.out.println(i);
		System.out.println("\n\n"+prog+"\n\n");
		System.out.println(m+"\n");
		System.out.println("\nPROCESS BEGIN\n\n");
		m.process(prog);
		System.out.println(m);
		System.out.println("\n\nPROCESS END\n\n");
		config(m,cfg);
		System.out.println("Fin de la configuration :\n"+m);
		System.out.println("\n\n"+prog2+"\n");
		System.out.println("\nPROCESS BEGIN\n\n");
		m.process(prog2);
		System.out.println("\n\nPROCESS END\n\n");
		config(m,cfg2);
		System.out.println("Fin de la configuration :\n"+m);
		System.out.println("\n\n"+prog3+"\n");
		System.out.println("\nPROCESS BEGIN\n\n");
		m.process(prog3);
		System.out.println("\n\nPROCESS END\n\n");
	}
}

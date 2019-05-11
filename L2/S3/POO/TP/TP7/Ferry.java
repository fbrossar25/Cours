import java.util.*;
class Ferry{
	ArrayList<Vehicule> coVehicule;
	Ferry(){
		coVehicule = new ArrayList();
	}
	double addVehicule(int type){
		switch(type){
			case 1:{
				coVehicule.add(new Voiture());
				return ((Vehicule)(coVehicule.get(coVehicule.size()-1))).getPrixTransport();
			}
			case 2:{
				coVehicule.add(new Moto());
				return ((Vehicule)(coVehicule.get(coVehicule.size()-1))).getPrixTransport();
			}
			case 3: {
				coVehicule.add(new Velo());
				return ((Vehicule)(coVehicule.get(coVehicule.size()-1))).getPrixTransport();
			}
			default:{
				System.out.println("\n\n Methode Ferry.add(int n) : n =(1,2,3) pour ajouter respectivement Voiture, Moto ou Vélo\n\n");
				return 0.0;
			}
		}
	}
	double recette(){
		double res=0.0;
		for(int i=0; i<coVehicule.size();i++){
			res += ((Vehicule)(coVehicule.get(i))).getPrixTransport();
		}
		return res;
	}
	int getNbVoiture(){
		return Voiture.getNombreInstances();
	}
	int getNbMoto(){
		return Moto.getNombreInstances();
	}
	int getNbVelo(){
		return Velo.getNombreInstances();
	}
}
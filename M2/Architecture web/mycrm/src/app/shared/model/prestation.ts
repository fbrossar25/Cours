import { PrestationInterface } from './../interfaces/prestation-interface';
import { StatePrestation } from '../enums/state-prestation.enum';
import { TypePrestation } from '../enums/type-prestation.enum';

type PartialPrestation = Partial<Prestation> & Pick <Prestation, 'id'> & Pick<Prestation, 'intitule'>;

export class Prestation implements PrestationInterface {
  id: string;
  intitule: string;
  date_debut: string = new Date().toISOString();
  date_fin: string;
  nb_jours = 1;
  tjm_ht = 100;
  taux_tva = 20;
  state: StatePrestation = StatePrestation.OPTION;
  type: TypePrestation = TypePrestation.FORMATION;

  constructor(fields?:  PartialPrestation) {
    if (fields) {
      Object.assign(this, fields);
    }
  }

  totalHT(): number {
    console.log('totalHT');
    return this.nb_jours * this.tjm_ht;
  }

  totalTTC(): number {
    return this.totalHT() * ((100 + this.taux_tva) / 100.0);
  }
}

import { TypePrestation } from '../enums/type-prestation.enum';
import { StatePrestation } from '../enums/state-prestation.enum';

export interface PrestationInterface {
  id: string;
  intitule: string;
  date_debut: string;
  date_fin: string;
  nb_jours: number;
  tjm_ht: number;
  taux_tva: number;
  state: StatePrestation;
  type: TypePrestation;
  totalHT(): number;
  totalTTC(): number;
}

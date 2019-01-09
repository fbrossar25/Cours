import { StatePrestation } from 'src/app/shared/enums/state-prestation.enum';
import { Prestation } from './../../shared/model/prestation';
import { TypePrestation } from 'src/app/shared/enums/type-prestation.enum';
export const PrestationsCollection: Prestation[] = [
new Prestation(),
new Prestation({id: '0', intitule: 'toto', state: StatePrestation.ENCAISSE}),
new Prestation({id: '42', intitule: 'titi', type: TypePrestation.PRESTATION }),
];

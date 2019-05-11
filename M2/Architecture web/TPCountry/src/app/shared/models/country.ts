import { Currency } from './currency';

export class Country {
  name: string;
  population: number;
  area: number;
  region: string;
  capital: string;
  currencies: Currency[];
  flag: string;
  alpha3Code: string;
}

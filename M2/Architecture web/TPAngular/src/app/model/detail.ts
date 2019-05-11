import {Quotes} from './quotes';

export class Detail {

  id: number;
  name: string;
  symbol: string;
  website_slug: string;
  rank: number;
  circulating_supply: number;
  total_supply: number;
  max_supply: number;
  last_updated: number;
  quotes : Quotes;
}


import { Injectable } from '@angular/core';
import {Data} from './model/data';
import {Coin} from './model/coin';
import {DataDetail} from './model/DataDetail';
import {HttpClient } from '@angular/common/http';
import {Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class ComapiService {

urlListCrypto = "https://api.coinmarketcap.com/v2/listings/";
urlDetailCrypto = "https://api.coinmarketcap.com/v2/ticker";

  constructor(private httpClient : HttpClient) { }

  public getListCryptoMock () : Coin [] {
    var listCryptoMock : Data = {"data":[{"id":1,"name":"BITCOIN","symbol": "BTC","website_slug":""},{"id":2,"name":"LITCOIN","symbol": "LC","website_slug":""}]};
    return listCryptoMock.data;
    }

    public getListCrypto () : Observable<Data> {
      return this.httpClient.get<Data>(this.urlListCrypto)
      }

      public getListCryptoDetail (id:number) : Observable<DataDetail> {
        return this.httpClient.get<DataDetail>(this.urlDetailCrypto
          + "/"+ id + "/");
        }
}

import { Injectable } from '@angular/core';
import { Coin } from './model/coin';
import { Data } from './model/data';
import {HttpClient } from '@angular/common/http'
import {Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class ComapiService {
  urlListCrypto = "https://api.coinmarketcap.com/v2/listings/";
  urlDetailCrypto = "https://api.coinmarketcap.com/v2/ticker";
  constructor(private httpClient : HttpClient) { }
  public getListCrypto () : Observable<Data> {
    return this.httpClient.get<Data>(this.urlListCrypto)
  }
}

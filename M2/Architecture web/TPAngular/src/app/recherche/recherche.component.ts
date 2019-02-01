import { Component, OnInit } from '@angular/core';
import {Coin} from '../model/coin';
import { ComapiService } from '../comapi.service';
@Component({
  selector: 'app-recherche',
  templateUrl: './recherche.component.html',
  styleUrls: ['./recherche.component.css']
})
export class RechercheComponent implements OnInit {

  constructor(private comapi: ComapiService) { }
  nomCrypto : string = "BITCOIN";

  listCrypto : Coin [];

  onclick () {
    this.comapi.getListCrypto().subscribe(d => {this.listCrypto = d.data; console.log(this.listCrypto);});
  }

  ngOnInit() {
  }

}

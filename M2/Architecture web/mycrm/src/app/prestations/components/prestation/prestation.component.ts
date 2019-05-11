import { TypePrestation } from 'src/app/shared/enums/type-prestation.enum';
import { Prestation } from './../../../shared/model/prestation';
import { Component, OnInit, Input } from '@angular/core';
import { StatePrestation } from 'src/app/shared/enums/state-prestation.enum';

@Component({
  selector: 'app-prestation',
  templateUrl: './prestation.component.html',
  styleUrls: ['./prestation.component.scss']
})
export class PrestationComponent implements OnInit {
  @Input()
  presta: Prestation;
  states = Object.values(StatePrestation);
  types = Object.values(TypePrestation);
  constructor() { }

  ngOnInit() {
  }

}
